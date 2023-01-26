/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:41:20 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/26 22:42:15 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void	free_double_char_array(char ***array);

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
		free_double_char_array(&exe_unit->cmd_argv);
	if (exe_unit->redir_list)
		free_redir_array(&exe_unit->redir_list);
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
