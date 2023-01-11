/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:52:43 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/11 14:39:23 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"

int	parse_list(t_node **root, t_token *token, int *offset)
{
	t_node	*node;

	node = *root;
	node->first_child = create_tree_node();
	if (!parse_pipeline(node->first_child, token, offset))
		return (SYNTAX_ERROR);
	if (token[*offset].type == TOKEN_AND_IF)
		node->type = NODE_AND_IF;
	else if (token[*offset].type == TOKEN_OR_IF)
		node->type = NODE_OR_IF;
	else
	{
		*root = node->first_child;
		free(node);
		return (SYNTAX_OK);
	}
	*offset += 1;
	node->first_child->next_sibling = create_tree_node();
	if (!parse_list(&(node->first_child->next_sibling), token, offset))
		return (SYNTAX_ERROR);
	return (SYNTAX_OK);
}
