/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_generate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:50:47 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/26 20:12:24 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal_handle.h"
#include "env_manager.h"
#include "heredoc_internal.h"
#include "wrap.h"
#include "sys/wait.h"

static void	get_random_temp_file_name(char **file_name)
{
	static char	*charset = CHARSET;
	int			fd;
	char		*new_file_name;
	char		buf[2];

	fd = w_open("/dev/urandom", O_RDONLY, OPEN_MODE_NONE);
	(*file_name) = ft_strdup(INITIAL_TEMP_FILENAME);
	buf[1] = 0;
	while (!access((*file_name), F_OK))
	{
		if (ft_strlen((*file_name)) == 255)
		{
			free((*file_name));
			(*file_name) = ft_strdup(INITIAL_TEMP_FILENAME);
		}
		w_read(fd, buf, 1);
		buf[0] = charset[(buf[0] + 255) % 63];
		new_file_name = ft_strjoin((*file_name), buf);
		free((*file_name));
		(*file_name) = new_file_name;
	}
	w_close(fd);
}

static void	get_heredoc_input(int fd, char *delimiter, int quote)
{
	char		*line;
	// extern int	rl_catch_signals;

	// rl_catch_signals = 1;
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

void	generate_here_document(char **heredoc, char *delimiter, int quote)
{
	int		fd;
	int		pid;
	int		stat;

	set_signal(IGNORE, IGNORE);
	pid = w_fork();
	if (pid == 0)
	{
		set_signal(DEFAULT, IGNORE);
		fd = w_open(*heredoc, O_WRONLY | O_CREAT | O_APPEND, 0644);
		get_heredoc_input(fd, delimiter, quote);
		w_close(fd);
		exit_program();
	}
	w_wait(&stat);
	set_signal(CATCH, CATCH);
	if (WIFSIGNALED(stat) && WTERMSIG(stat) == SIGINT)
	{
		heredoc_interupted(*heredoc);
		free(*heredoc);
		*heredoc = NULL;
	}
}

char	*process_heredoc(char *word)
{
	const int	delimiter_len = get_delimiter_len(word);
	int			quote;
	char		*delimiter;
	char		*heredoc;

	get_delimiter(&delimiter, &quote, delimiter_len, word);
	get_random_temp_file_name(&heredoc);
	generate_here_document(&heredoc, delimiter, quote);
	free(delimiter);
	return (heredoc);
}
