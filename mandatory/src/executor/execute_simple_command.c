/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:24:34 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/27 19:03:58 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor_internal.h"

void	do_expansion(t_execute_unit *exe_unit);

static void	run_child(t_execute_unit *exe_unit, t_pipeline *pl, int nth)
{
	const char	**envp = (const char **)env_get_defined_variable_list();

	do_expansion(exe_unit);
	set_standard_stream(pl, exe_unit->redir_list, nth);
	set_signal(DEFAULT, DEFAULT);
	if (get_builtin_cmd_idx(exe_unit->cmd_name) >= 0)
	{
		execute_builtin(exe_unit);
		exit_program();
	}
	else
	{
		if (access_command(&exe_unit->cmd_name) == SUCCESS)
			execve(exe_unit->cmd_name, exe_unit->cmd_argv, (char *const *)envp);
		else
			exit_program();
		exit(1);
	}
}

int	execute_simple_command(t_execute_unit *exe_unit, t_pipeline *pl, int nth)
{
	const int	last = (nth == pl->child_cnt);
	int			pid;

	if (pl->child_cnt != 1 && !last)
		open_new_pipe(pl->new_pipe_fd);
	pid = fork();
	if (pid < 0)
		exit(1);
	else if (pid == 0)
	{
		run_child(exe_unit, pl, nth);
	}
	else
	{
		if (last)
			pl->last_child_pid = pid;
		if (pl->pipe_exist)
			close_pipe_in_parent(pl->old_pipe_fd, pl->new_pipe_fd, \
														(nth == 1), last);
		ft_memcpy(pl->old_pipe_fd, pl->new_pipe_fd, sizeof(int [2]));
	}
	return (SUCCESS);
}
