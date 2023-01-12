/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:33:19 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/12 19:52:48 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "executor.h"
#include "minishell.h"
#include "parser.h"

#define PIPE_READ 0
#define PIPE_WRITE 1

// root의 타입을 확인해본다
	// PIPELINE이면 first child로 가고, 
void	pipex(void)
{
	int pipefd[2];
	int	i;

	pipe(pipefd);
	i = 0;
	while (i < 2)
	{
		// 포크 뜬 후 
	}	
}

void	executor(t_node *tree)
{
	if (tree->type == NODE_PIPELINE)
	{
		execute_simple_cmd
	}
	else if (tree->type == NODE_AND_IF)	
		executor(tree->first_child);
	else
		return ;
}

// cat <infile | cat -e >outfile

// node[0]
	// - node[1]
	// - node[2]
int main()
{
	t_node	node[10];
	t_node	*root = &node[0];

	node[0].type = NODE_PIPELINE;
	node[1].type = NODE_SIMPLE_CMD;
	node[2].type = NODE_SIMPLE_CMD;

	node[0].first_child = node[1];
	node[1].next_sibling = node[2];

	node[1].exe_unit = malloc(sizeof(t_execute_unit));
	node[1].exe_unit->cmd_name = "/bin/cat";
	node[1].exe_unit->cmd_argv = create_queue(QUEUE_INITIAL_SIZE, QUEUE_STR_ONLY);
	node[1].exe_unit->redir_list = create_queue(QUEUE_INITIAL_SIZE, QUEUE_INTSTR);
	queue_push_intstr(node[1].exe_unit->redir_list, TOKEN_REDIR_IN, "infile");

	node[2].exe_unit = malloc(sizeof(t_execute_unit));
	node[2].exe_unit->cmd_name = "/bin/cat";
	node[2].exe_unit->cmd_argv = create_queue(QUEUE_INITIAL_SIZE, QUEUE_STR_ONLY);
	node[2].exe_unit->redir_list = create_queue(QUEUE_INITIAL_SIZE, QUEUE_INTSTR);
	queue_push_str(node[2].exe_unit->cmd_argv, "-e");
	queue_push_intstr(node[2].exe_unit->redir_list, TOKEN_REDIR_OUT, "outfile");

	
}