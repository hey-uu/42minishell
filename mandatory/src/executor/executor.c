/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:33:19 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 15:00:51 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "executor.h"
#include "minishell.h"
#include "parser.h"
#include "env_manager.h"

int	executor(t_node *node)
{
	if (node->type == NODE_PIPELINE)
		return (execute_pipeline(node->first_child));
	else if (node->type == NODE_AND_IF)
	{
		if (executor(node->first_child) == EXIT_SUCCESS)
			executor(node->first_child->next_sibling);
	}
	else if (node->type == NODE_OR_IF)
	{
		if (executor(node->first_child) != EXIT_SUCCESS)
			executor(node->first_child->next_sibling);
	}
	return (SUCCESS);
}
