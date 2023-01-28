/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:41:20 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 15:53:08 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "tree_internal.h"

static void	free_redir_array(t_redir **redir_list)
{
	int	i;

	i = 0;
	while ((*redir_list)[i].num != TOKEN_NONE)
	{
		free((*redir_list)[i].str);
		i++;
	}
	free(*redir_list);
	*redir_list = NULL;
}

static void	destroy_execute_unit(t_execute_unit *exe_unit)
{
	if (!exe_unit)
		return ;
	if (exe_unit->cmd_name)
		free(exe_unit->cmd_name);
	if (exe_unit->q_cmd_argv)
		destroy_queue(&exe_unit->q_cmd_argv);
	if (exe_unit->q_redir_list)
		destroy_queue(&exe_unit->q_redir_list);
	if (exe_unit->cmd_argv)
		free_str_array(&exe_unit->cmd_argv);
	if (exe_unit->redir_list)
		free_redir_array(&exe_unit->redir_list);
	free(exe_unit);
}

void	destroy_tree(t_node *node)
{
	if (!node)
		return ;
	destroy_tree(node->first_child);
	destroy_tree(node->next_sibling);
	destroy_execute_unit(node->exe_unit);
	free(node);
}
