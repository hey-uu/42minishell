/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:33:19 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/17 16:15:36 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "executor.h"
#include "minishell.h"
#include "parser.h"

int	executor(t_node *node, char *envp[])
{
	if (node->type == NODE_PIPELINE)
		return (execute_pipeline(node->first_child, envp));
	else if (node->type == NODE_AND_IF)
	{
		if (executor(node->first_child, envp) == EXIT_SUCCESS)
			executor(node->first_child->next_sibling, envp);
	}
	else if (node->type == NODE_OR_IF)
	{
		if (executor(node->first_child, envp) != EXIT_SUCCESS)
			executor(node->first_child->next_sibling, envp);
	}
	return (SUCCESS);
}
