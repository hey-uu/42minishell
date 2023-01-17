/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:24:34 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/17 16:33:13 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "executor.h"
#include "minishell.h"
#include "parser.h"

static void	open_new_pipe(int new_pipe_fd[2], int *pipe_exist)
{
	pipe(new_pipe_fd);
	*pipe_exist = 1;
}

static void	close_pipe_in_parent(int old_pipe_fd[2], int new_pipe_fd[2], int first, int last)
{
	if (first)
	{
		close(new_pipe_fd[P_WRITE]);
	}
	else if (last)
	{
		close(old_pipe_fd[P_READ]);
	}
	else
	{
		close(old_pipe_fd[P_READ]);
		close(new_pipe_fd[P_WRITE]);
	}
}

static void	run_child(t_execute_unit *exe_unit, char **envp, t_pipeline *pl, int nth)
{
	set_standard_stream(pl, exe_unit->redir_list, nth);
	if (access_command_path(&exe_unit->cmd_name, envp) == FAILURE)
		printf("(guemzzoki): command not found: %s\n", exe_unit->cmd_name);
	execve(exe_unit->cmd_name, exe_unit->cmd_argv->strarr, envp);
}

int	execute_simple_command(t_execute_unit *exe_unit, char **envp, t_pipeline *pl, int nth)
{
	const int	last = (nth == pl->child_cnt);
	int			pid;

	if (pl->child_cnt != 1 && !last)
		open_new_pipe(pl->new_pipe_fd, &pl->pipe_exist);
	pid = fork();
	if (pid < 0)
		exit(1);
	else if (pid == 0)
	{
		run_child(exe_unit, envp, pl, nth);
		exit(1);
	}
	else
	{
		if (last)
			pl->last_child_pid = pid;	
		close_pipe_in_parent(pl->old_pipe_fd, pl->new_pipe_fd, (nth == 1), last);
		ft_memcpy(pl->old_pipe_fd, pl->new_pipe_fd, sizeof(int[2]));
	}
	return (SUCCESS);
}
