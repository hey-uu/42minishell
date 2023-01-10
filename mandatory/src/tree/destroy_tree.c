/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:36:35 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/10 15:37:15 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tree.h"

static void	destroy_simple_command(t_simple_cmd *simple_cmd)
{
	if (!simple_cmd)
		return ;
	free(simple_cmd->name);
	destroy_queue(simple_cmd->argv);
	free(simple_cmd);
}

static void	destroy_redirect_list(t_redir_list *io_list)
{
	if (!io_list)
		return ;
	destroy_queue(io_list->redir_in);
	destroy_queue(io_list->redir_out);
	free(io_list);
}

void	destroy_tree(t_node *parent)
{
	if (!parent)
		return ;
	destroy_tree(parent->first_child);
	destroy_tree(parent->next_sibling);
	if (parent->type == NODE_SIMPLE_CMD)
	{
		destroy_simple_command(parent->exe_unit.simple_cmd);
		destroy_redirect_list(parent->exe_unit.io_list);
	}
	if (parent->type == NODE_SUBSHELL)
		destroy_redirect_list(parent->exe_unit.io_list);
	free(parent);
}
