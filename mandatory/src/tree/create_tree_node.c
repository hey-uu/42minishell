/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tree_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:18:50 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/11 10:58:20 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "tree.h"

t_node	*create_tree_node(void)
{
	t_node	*new;

	new = ft_malloc(sizeof(t_node));
	new->type = NODE_NONE;
	new->exe_unit.simple_cmd = NULL;
	new->exe_unit.redir_list = NULL;
	new->first_child = NULL;
	new->next_sibling = NULL;
	return (new);
}
