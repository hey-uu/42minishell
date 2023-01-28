/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:28:06 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/28 16:55:13 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include "executor_internal.h"

static int	count_childs_of_pipeline(t_node *node)
{
	int	cnt;

	cnt = 0;
	while (node)
	{
		node = node->next_sibling;
		cnt++;
	}
	return (cnt);
}

static void	wait_childs_of_pipeline(int child_cnt, int last_child_pid, \
														int *pl_exit_stat)
{
	int			i;
	int			stat;
	int			term_pid;

	set_signal(IGNORE, IGNORE);
	i = 0;
	while (i < child_cnt)
	{
		term_pid = wait(&stat);
		if (term_pid == -1)
			exit(1);
		else if (term_pid == last_child_pid)
		{
			if (WIFSIGNALED(stat))
			{
				*pl_exit_stat = WTERMSIG(stat) + 128;
				if (WTERMSIG(stat) == SIGINT)
					write(1, "\n", 1);
			}
			else
				*pl_exit_stat = WEXITSTATUS(stat);
		}
		i++;
	}
	set_signal(CATCH, CATCH);
}

int	execute_pipeline(t_node *node)
{
	t_pipeline	pl;
	int			nth;

	if (!node->next_sibling && \
			get_builtin_cmd_idx(node->exe_unit->cmd_name) >= 0)
		return (execute_single_builtin(node->exe_unit));
	else
	{
		pl.child_cnt = count_childs_of_pipeline(node);
		pl.pipe_exist = (pl.child_cnt >= 2);
		nth = 1;
		while (nth <= pl.child_cnt)
		{
			if (node->type == NODE_SUBSHELL)
				execute_subshell(node, &pl, nth);
			else
				execute_simple_command(node->exe_unit, &pl, nth);
			node = node->next_sibling;
			nth++;
		}
		wait_childs_of_pipeline(pl.child_cnt, pl.last_child_pid, \
													&pl.exit_status);
	}
	exit_stat_update(pl.exit_status);
	return (pl.exit_status);
}
