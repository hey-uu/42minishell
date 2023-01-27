/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:52:43 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/27 20:15:02 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"

int	parse_list(t_node *node, t_token *tokens, int *offset)
{
	t_node	*new_node;

	if (parse_pipeline(node, tokens, offset) == FAILURE)
		return (FAILURE);
	if (!(tokens[*offset].type == TOKEN_AND_IF || \
										tokens[*offset].type == TOKEN_OR_IF))
		return (SUCCESS);
	new_node = create_tree_node(node->root);
	new_node->type = tokens[*offset].type;
	(*offset)++;
	new_node->first_child = *(node->root);
	*(node->root) = new_node;
	new_node->first_child->next_sibling = create_tree_node(node->root);
	if (parse_list(new_node->first_child->next_sibling, tokens, offset) \
																	== FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
