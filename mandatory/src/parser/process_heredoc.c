/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:50:47 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 10:30:58 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <readline/readline.h>
#include "libft.h"
#include "expansion.h"
#include "env_manager.h"

#define CHARSET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"
#define INITIAL_TEMP_FILENAME "/tmp/goldsh_"
#define PS_HEREDOC "goldsh heredoc > "

char	*get_random_temp_file_name(void)
{
	static char	*charset = CHARSET;
	int			fd;
	char		*file_name;
	char		*new_file_name;
	char		buf[2];

	fd = open("/dev/urandom", O_RDONLY);
	file_name = ft_strdup(INITIAL_TEMP_FILENAME);
	buf[1] = 0;
	while (!access(file_name, F_OK))
	{
		if (ft_strlen(file_name) == 255)
		{
			free(file_name);
			file_name = ft_strdup(INITIAL_TEMP_FILENAME);
		}
		read(fd, buf, 1);
		buf[0] = charset[(buf[0] + 255) % 63];
		new_file_name = ft_strjoin(file_name, buf);
		free(file_name);
		file_name = new_file_name;
	}
	close(fd);
	return (file_name);
}

int	expand_variable_in_heredoc(char *line, int fd)
{
	char	*variable;
	char	*value;
	int		idx;
	int		question_mark;

	idx = 1;
	variable = split_variable(&line[idx], &idx, &question_mark);
	if (!variable && question_mark == VAR_IS_NOT_QMARK)
		return (idx);
	if (question_mark == VAR_IS_QMARK)
		value = exit_stat_get_str();
	else
		value = env_get(variable);
	if (value)
		write(fd, value, ft_strlen(value));
	if (question_mark == VAR_IS_QMARK)
		free(value);
	free(variable);
	return (idx);
}

void	make_heredoc_with_expansion(char *line, int fd)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (line[i])
	{
		if (line[i] == '$' && (line[i + 1] && line[i + 1] != '$' && \
							line[i + 1] != '\'' && line[i + 1] != '\"'))
		{
			write(fd, line + i - len, len);
			i += expand_variable_in_heredoc(&line[i], fd);
			len = 0;
		}
		i++;
		len++;
	}
	if (len)
		write(fd, line + i - len, len);
}

void	get_heredoc_input(int fd, char *delimiter, int quote)
{
	char	*line;

	while (1)
	{
		line = readline(PS_HEREDOC);
		if (!line)
			break ;
		if (!ft_strncmp(line, delimiter, ft_strlen(line) + 1))
			break ;
		if (!quote)
			make_heredoc_with_expansion(line, fd);
		else
			write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
	free(line);
}

char	*generate_here_document(char *delimiter, int quote)
{
	char	*heredoc;
	int		fd;

	heredoc = get_random_temp_file_name();
	fd = open(heredoc, O_WRONLY | O_CREAT | O_APPEND, 0644);
	heredoc_is_in_process(heredoc, fd);
	if (fd < 0)
	{
		printf("failed to make temporary file for heredoc\n");
		return (NULL);
	}
	get_heredoc_input(fd, delimiter, quote);
	close(fd);
	heredoc_is_done();
	return (heredoc);
}

int	get_delimiter_len(char *word)
{
	int		quote;
	int		len;

	len = 0;
	quote = 0;
	while (*word)
	{
		if (!quote && (*word == '\'' || *word == '\"'))
			quote = *word;
		else if (quote && (*word == quote))
			quote = 0;
		else
			len++;
		word++;
	}
	return (len);
}

void	store_delimiter(char *delimiter, char *word)
{
	int		quote;
	int		i;

	i = 0;
	quote = 0;
	while (*word)
	{
		if (!quote && (*word == '\'' || *word == '\"'))
			quote = *word;
		else if (quote && (*word == quote))
			quote = 0;
		else
			delimiter[i++] = *word;
		word++;
	}
	delimiter[i] = '\0';
}

char	*process_heredoc(char *word)
{
	const int	delimiter_len = get_delimiter_len(word);
	int			quote;
	char		*delimiter;
	char		*heredoc;

	delimiter = ft_malloc(sizeof(char) * (delimiter_len + 1));
	store_delimiter(delimiter, word);
	quote = (delimiter_len != (int)ft_strlen(word));
	printf("> is quoted or not? %d\n delimiter len = %d\n word len = %zu\n", quote, delimiter_len, ft_strlen(word));
	heredoc = generate_here_document(delimiter, quote);
	return (heredoc);
}
