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

#include "tree.h"

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
// exe unit cmd_argv, redir_list 할당 해제 함수  추가
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
