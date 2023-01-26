/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_standard_stream.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:24:28 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/26 22:23:41 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "executor.h"
#include "minishell.h"
#include "parser.h"
#include "env_manager.h"
#include "wrapped_syscall.h"

int	do_redirecting(t_redir *redir_list)
{
	int	fd;
	int	i;

	i = 0;
	while (redir_list[i].num != TOKEN_NONE)
	{
		if (redir_list[i].num == TOKEN_REDIR_IN \
				|| redir_list[i].num == TOKEN_REDIR_IN_HERE)
		{
			fd = open(redir_list[i].str, O_RDONLY);
			if (fd < 0)
			{
				handle_execute_error(ERR_EXE_NO_SUCH_FILE_OR_DIR, \
												NULL, redir_list[i].str);
				return (FAILURE);
			}
			w_dup2(fd, STDIN_FILENO);
			if (redir_list[i].num == TOKEN_REDIR_IN_HERE)
				unlink(redir_list[i].str);
		}
		else if (redir_list[i].num == TOKEN_REDIR_OUT)
		{
			fd = open(redir_list[i].str, \
						O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (fd < 0)
			{
				handle_execute_error(ERR_EXE_NO_SUCH_FILE_OR_DIR, \
												NULL, redir_list[i].str);
				return (FAILURE);
			}
			w_dup2(fd, STDOUT_FILENO);
		}
		else if (redir_list[i].num == ERR_EXE_AMBIGUOUS_REDIR)
		{
			handle_execute_error(\
				ERR_EXE_AMBIGUOUS_REDIR, NULL, redir_list[i].str);
			return (FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

static void	do_piping(int old_pipe_fd[2], int new_pipe_fd[2], \
												int nth, int child_cnt)
{
	int	err[2];

	err[1] = 0;
	if (nth == 1)
	{
		close(new_pipe_fd[P_READ]);
		err[0] = w_dup2(new_pipe_fd[P_WRITE], STDOUT_FILENO);
		close(new_pipe_fd[P_WRITE]);
	}
	else if (nth == child_cnt)
	{
		err[0] = w_dup2(old_pipe_fd[P_READ], STDIN_FILENO);
		close(old_pipe_fd[P_READ]);
	}
	else
	{
		close(new_pipe_fd[P_READ]);
		err[0] = w_dup2(old_pipe_fd[P_READ], STDIN_FILENO);
		err[1] = w_dup2(new_pipe_fd[P_WRITE], STDOUT_FILENO);
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
