/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_generate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:50:47 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 20:27:47 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager.h"
#include "heredoc_internal.h"

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

char	*process_heredoc(char *word)
{
	const int	delimiter_len = get_delimiter_len(word);
	int			quote;
	char		*delimiter;
	char		*heredoc;

	delimiter = ft_malloc(sizeof(char) * (delimiter_len + 1));
	store_delimiter(delimiter, word);
	quote = (delimiter_len != (int)ft_strlen(word));
	heredoc = generate_here_document(delimiter, quote);
	free(delimiter);
	return (heredoc);
}
