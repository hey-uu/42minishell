/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_standard_stream.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:24:28 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/25 16:06:34 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "executor.h"
#include "minishell.h"
#include "parser.h"
#include "env_manager.h"

int	do_redirecting(t_redir *redir_list)
{
	int	fd;
	int	err;
	int	i;

	i = 0;
	while (redir_list[i].num != TOKEN_NONE)
	{
		if (redir_list[i].num == TOKEN_REDIR_IN \
				|| redir_list[i].num == TOKEN_REDIR_IN_HERE)
		{
			fd = open(redir_list[i].str, O_RDONLY);
			err = dup2(fd, STDIN_FILENO);
			if (redir_list[i].num == TOKEN_REDIR_IN_HERE)
				unlink(redir_list[i].str);
		}
		else if (redir_list[i].num == TOKEN_REDIR_OUT)
		{
			fd = open(redir_list[i].str, \
						O_WRONLY | O_CREAT | O_TRUNC, 0644);
			err = dup2(fd, STDOUT_FILENO);
		}
		else if (redir_list[i].num == ERR_EXE_AMBIGUOUS_REDIR)
		{
			handle_execute_error(\
			ERR_EXE_AMBIGUOUS_REDIR, NULL, redir_list[i].str);
			return (ERR_EXE_AMBIGUOUS_REDIR);
		}
		if (err < 0)
		{
			exit_by_error("dup2 error");
			return (ERR_EXE_SYSCALL_FAILED);
		}
		i++;
	}
	return (ERR_EXE_NONE);
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

void	set_standard_stream(t_pipeline *pl, t_redir *redir_list, int nth)
{
	if (pl && pl->pipe_exist)
		do_piping(pl->old_pipe_fd, pl->new_pipe_fd, nth, pl->child_cnt);
	if (do_redirecting(redir_list) > 0)
		exit_program();
}
