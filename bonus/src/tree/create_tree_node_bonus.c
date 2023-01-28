/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tree_node_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:18:50 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:18:47 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tree_internal_bonus.h"

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
