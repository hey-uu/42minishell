/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_standard_stream.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:24:28 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/28 12:57:11 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "wrapped_syscall.h"
#include "executor_internal.h"

static int	input_redirect(char *filename, int redir_type)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		handle_execute_error(ERR_EXE_NO_SUCH_FILE_OR_DIR, NULL, filename);
		return (FAILURE);
	}
	w_dup2(fd, STDIN_FILENO);
	if (redir_type == REDIR_HEREDOC)
		unlink(filename);
	return (SUCCESS);
}

static int	output_redirect(char *filename, int redir_type)
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
	return (SUCCESS);
}

int	do_redirecting(t_redir *redir_list)
{
	const t_redirect	redir_func[] = {
	[REDIR_IN] = input_redirect,
	[REDIR_OUT] = output_redirect,
	[REDIR_APPEND] = output_redirect,
	[REDIR_HEREDOC] = input_redirect,
	};
	int					i;

	i = 0;
	while (redir_list[i].num != REDIR_NONE)
	{
		if (redir_list[i].num == ERR_EXE_AMBIGUOUS_REDIR)
		{
			handle_execute_error(\
				ERR_EXE_AMBIGUOUS_REDIR, NULL, redir_list[i].str);
			return (FAILURE);
		}
		else
			if (redir_func[redir_list[i].num] \
					(redir_list[i].str, redir_list[i].num) == FAILURE)
				return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

static void	do_piping(int old_pipe_fd[2], int new_pipe_fd[2], \
												int nth, int child_cnt)
{
	if (nth == 1)
	{
		close(new_pipe_fd[P_READ]);
		w_dup2(new_pipe_fd[P_WRITE], STDOUT_FILENO);
		close(new_pipe_fd[P_WRITE]);
	}
	else if (nth == child_cnt)
	{
		w_dup2(old_pipe_fd[P_READ], STDIN_FILENO);
		close(old_pipe_fd[P_READ]);
	}
	else
	{
		close(new_pipe_fd[P_READ]);
		w_dup2(old_pipe_fd[P_READ], STDIN_FILENO);
		w_dup2(new_pipe_fd[P_WRITE], STDOUT_FILENO);
		close(old_pipe_fd[P_READ]);
		close(new_pipe_fd[P_WRITE]);
	}
}

void	set_standard_stream(t_pipeline *pl, t_redir *redir_list, int nth)
{
	if (pl && pl->pipe_exist)
		do_piping(pl->old_pipe_fd, pl->new_pipe_fd, nth, pl->child_cnt);
	if (do_redirecting(redir_list) == FAILURE)
		exit_program();
}
