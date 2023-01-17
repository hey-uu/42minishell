#include "tree.h"
#include "executor.h"
#include "minishell.h"
#include "parser.h"

static int count_childs_of_pipeline(t_node *node)
{
	int cnt;

	cnt = 0;
	while (node)
	{
		node = node->next_sibling;
		cnt++;
	}
	return (cnt);
}

static void	wait_childs_of_pipeline(int child_cnt, int last_child_pid, int *pl_exit_stat)
{
	int			i;
	int			stat_loc;
	int			term_pid;
	
	i = 0;
	while (i < child_cnt)
	{
		term_pid = wait(&stat_loc);
		// printf("Child %d is terminated...\n", term_pid);
		if (term_pid == -1)
			exit(1);
		else if (term_pid == last_child_pid)
			*pl_exit_stat = stat_loc;
		i++;
	}
}

int	execute_pipeline(t_node *node, char **envp)
{
	t_pipeline	pl;
	int			nth;

	if (!node->next_sibling && \
			get_builtin_cmd_idx(node->exe_unit->cmd_name) >= 0)
		return (execute_single_builtin(node->exe_unit, envp));
	else
	{
		pl.pipe_exist = 0;
		pl.child_cnt = count_childs_of_pipeline(node);
		nth = 1;
		while (nth <= pl.child_cnt)
		{
			if (node->type == NODE_SUBSHELL)
				execute_subshell(node, envp, &pl, nth);
			else
				execute_simple_command(node->exe_unit, envp, &pl, nth);
			node = node->next_sibling;
			nth++;
		}
		wait_childs_of_pipeline(pl.child_cnt, pl.last_child_pid, &pl.exit_status); 
	}
	return (pl.exit_status);
}