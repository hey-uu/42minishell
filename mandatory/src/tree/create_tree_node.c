/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tree_node.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:18:50 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 20:31:03 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tree_internal.h"

t_node	*create_tree_node(t_node **root)
{
	t_node	*new;

	new = ft_malloc(sizeof(t_node));
	new->type = NODE_NONE;
	new->exe_unit = NULL;
	new->root = root;
	new->first_child = NULL;
	new->next_sibling = NULL;
	return (new);
}
