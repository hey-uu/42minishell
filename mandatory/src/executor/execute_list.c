/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:23:03 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/27 08:03:20 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "executor.h"
#include "minishell.h"
#include "env_manager.h"

int	execute_list(t_node *node)
{
	if (node->type == NODE_PIPELINE)
		return (execute_pipeline(node->first_child));
	else if (node->type == NODE_AND_IF)
	{
		if (execute_list(node->first_child) == EXIT_SUCCESS)
			execute_list(node->first_child->next_sibling);
	}
	else if (node->type == NODE_OR_IF)
	{
		if (execute_list(node->first_child) != EXIT_SUCCESS)
			execute_list(node->first_child->next_sibling);
	}
	return (SUCCESS);
}