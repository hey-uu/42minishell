/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_subshell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:28:14 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/27 19:04:20 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor_internal.h"

void	expand_redir_list(t_queue **q_redir_list, t_intstr **redir_list);

int	execute_subshell(t_node *node, t_pipeline *pl, int nth)
{
	const int	last = (nth == pl->child_cnt);
	int			pid;
	int			exit_code;

	if (pl->child_cnt != 1 && !last)
		open_new_pipe(pl->new_pipe_fd);
	pid = fork();
	if (pid < 0)
		exit(1);
	else if (pid == 0)
	{
		expand_redir_list(&node->exe_unit->q_redir_list, \
							&node->exe_unit->redir_list);
		set_standard_stream(pl, node->exe_unit->redir_list, nth);
		exit_code = execute_list(node->first_child);
		exit(0);
	}
	else
	{
		if (last)
			pl->last_child_pid = pid;
		if (pl->pipe_exist)
			close_pipe_in_parent(pl->old_pipe_fd, pl->new_pipe_fd, \
													(nth == 1), last);
		ft_memcpy(pl->old_pipe_fd, pl->new_pipe_fd, sizeof(int) * 2);
	}
	return (SUCCESS);
}
