#include "tree.h"
#include "executor.h"
#include "minishell.h"
#include "parser.h"

int	execute_subshell(t_node *node, char **envp, t_pipeline *pl, int nth)
{
	int			pid;

	// pid = fork();
	// do_piping(pl->pipe_fd, nth);
	// if (pid == 0)
	// {
	// 	do_redirecting(node->exe_unit->redir_list);
	// 	executor(node->first_child, envp);
	// }
	// if (nth)
	// {
	// 	close(pl->pipe_fd[P_READ]);
	// 	pl->nth_child_pid = pid;
	// }
	// close(pl->pipe_fd[P_WRITE]);
	return (SUCCESS);
}