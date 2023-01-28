/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_standard_stream.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:24:28 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/28 19:22:56 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "wrapped_syscall.h"
#include "executor_internal.h"

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
