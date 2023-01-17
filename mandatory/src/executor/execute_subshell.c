#include "tree.h"
#include "executor.h"
#include "minishell.h"
#include "parser.h"

int	execute_subshell(t_node *node, char **envp, t_pipeline *pl, int nth)
{
	const int	last = (nth == pl->child_cnt);
	int			pid;
	int			exit_code;

	if (pl->child_cnt != 1 && !last)
		open_new_pipe(pl->new_pipe_fd);
	pid = fork();
	if (pid < 0)
		exit(1);
	// set_standard_stream(pl, node->exe_unit->redir_list, nth);
	else if (pid == 0)
	{
		set_standard_stream(pl, node->exe_unit->redir_list, nth);
		exit_code = executor(node->first_child, envp);
		printf("subshell child process status: %d", exit_code);
		exit(0);
	}
	else
	{
		if (last)
			pl->last_child_pid = pid;
		close_pipe_in_parent(pl->old_pipe_fd, pl->new_pipe_fd, \
													(nth == 1), last);
		ft_memcpy(pl->old_pipe_fd, pl->new_pipe_fd, sizeof(int[2]));
	}
	return (SUCCESS);
}

