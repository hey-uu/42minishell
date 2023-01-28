/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_list_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:23:03 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/28 16:17:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor_internal_bonus.h"

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
