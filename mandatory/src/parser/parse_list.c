/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:52:43 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/10 15:52:45 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_list(t_node **root, t_token *tokens, int offset)
{
	t_node	*node;
	int		cnt;
	int		res;

	node = *root;
	node->first_child = create_tree_node();
	res = parse_pipeline(node->first_child, tokens, offset);
	if (!res)
		return (0);
	cnt = res;
	if (tokens[offset + cnt].type == TOKEN_AND_IF)
		node->type = NODE_AND_IF;
	else if (tokens[offset + cnt].type == TOKEN_OR_IF)
		node->type = NODE_OR_IF;
	else
	{
		*root = node->first_child;
		free(node);
		return (cnt);
	}
	cnt++;
	node->first_child->next_sibling = create_tree_node();
	res = parse_list(&(node->first_child->next_sibling), tokens, offset + cnt);
	if (!res)
		return (0);
	cnt += res;
	return (cnt);
}
