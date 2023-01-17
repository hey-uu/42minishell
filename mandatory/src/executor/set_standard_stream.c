/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_standard_stream.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:24:28 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/17 23:49:19 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "executor.h"
#include "minishell.h"
#include "parser.h"

static void	do_redirecting(t_queue *redir_list)
{
	int	fd;
	int	err;
	int	i;

	i = 0;
	while (i < redir_list->used_size)
	{
		if (redir_list->iarr[i] == TOKEN_REDIR_IN)
		{
			fd = open(redir_list->strarr[i], O_RDONLY);
			err = dup2(fd, STDIN_FILENO);
		}
		else if (redir_list->iarr[i] == TOKEN_REDIR_OUT)
		{
			fd = open(redir_list->strarr[i], \
						O_WRONLY | O_CREAT | O_TRUNC, 0644);
			err = dup2(fd, STDOUT_FILENO);
		}
		if (err < 0)
			exit_by_error("dup2 error");
		i++;
	}
}

static void	do_piping(int old_pipe_fd[2], int new_pipe_fd[2], \
												int nth, int child_cnt)
{
	int	err[2];

	err[1] = 0;
	if (nth == 1)
	{
		close(new_pipe_fd[P_READ]);
		err[0] = dup2(new_pipe_fd[P_WRITE], STDOUT_FILENO);
		close(new_pipe_fd[P_WRITE]);
	}
	else if (nth == child_cnt)
	{
		err[0] = dup2(old_pipe_fd[P_READ], STDIN_FILENO);
		close(old_pipe_fd[P_READ]);
	}
	else
	{
		close(new_pipe_fd[P_READ]);
		err[0] = dup2(old_pipe_fd[P_READ], STDIN_FILENO);
		err[1] = dup2(new_pipe_fd[P_WRITE], STDOUT_FILENO);
		close(old_pipe_fd[P_READ]);
		close(new_pipe_fd[P_WRITE]);
	}
	if (err[0] < 0 || err[1] < 0)
		exit_by_error("dup2 error");
}

void	set_standard_stream(t_pipeline *pl, t_queue *redir_list, int nth)
{
	if (pl && pl->pipe_exist)
		do_piping(pl->old_pipe_fd, pl->new_pipe_fd, nth, pl->child_cnt);
	do_redirecting(redir_list);
}
