/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redirecting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:08:41 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/28 19:46:23 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "wrapped_syscall.h"
#include "executor_internal.h"

static int	io_type(int redir_type)
{
	if (redir_type == REDIR_IN || redir_type == REDIR_HEREDOC)
		return (IN);
	else if (redir_type == REDIR_OUT || redir_type == REDIR_APPEND)
		return (OUT);
	else
		return (-1);
}

static int	redirect_input(char *filename, int redir_type)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		handle_execute_error(ERR_EXE_NO_SUCH_FILE_OR_DIR, NULL, filename);
		return (FAILURE);
	}
	if (redir_type == REDIR_HEREDOC)
		unlink(filename);
	w_dup2(fd, STDIN_FILENO);
	close(fd);
	return (SUCCESS);
}

static int	redirect_output(char *filename, int redir_type)
{
	int	fd;

	(void)redir_type;
	if (redir_type == REDIR_APPEND)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		handle_execute_error(ERR_EXE_NO_SUCH_FILE_OR_DIR, NULL, filename);
		return (FAILURE);
	}
	w_dup2(fd, STDOUT_FILENO);
	close(fd);
	return (SUCCESS);
}

static int	process_redirect(int redir_type, char *filename)
{
	const t_redirect	redir_func[] = {
	[REDIR_IN] = redirect_input,
	[REDIR_OUT] = redirect_output,
	[REDIR_APPEND] = redirect_output,
	[REDIR_HEREDOC] = redirect_input,
	};

	if (redir_type == ERR_EXE_AMBIGUOUS_REDIR)
	{
		handle_execute_error(ERR_EXE_AMBIGUOUS_REDIR, NULL, filename);
		return (FAILURE);
	}
	else
		return (redir_func[redir_type](filename, redir_type));
}

int	do_redirecting(t_redir *redir_list)
{
	int					prev_std_fd[2];
	int					i;

	prev_std_fd[IN] = 0;
	prev_std_fd[OUT] = 0;
	i = 0;
	while (redir_list[i].num != REDIR_NONE)
	{
		// dprintf(2, "prev in: %d, prev out: %d\n", prev_std_fd[IN], prev_std_fd[OUT]);
		{
			if (io_type(redir_list[i].num) == IN && prev_std_fd[IN] != 0)
			{
				// dprintf(2, "close fd: %d\n", prev_std_fd[IN]);
				close(prev_std_fd[IN]);
			}
			else if (io_type(redir_list[i].num) == OUT && prev_std_fd[OUT] != 0)
			{
				// dprintf(2, "close fd: %d\n", prev_std_fd[OUT]);
				close(prev_std_fd[OUT]);
			}
		}
		if (process_redirect(redir_list[i].num, redir_list[i].str) == SUCCESS)
		{
			;
			// prev_std_fd[IN] = dup(STDIN_FILENO);
			// prev_std_fd[OUT] = dup(STDOUT_FILENO);
		}
		i++;
	}
	return (SUCCESS);
}
