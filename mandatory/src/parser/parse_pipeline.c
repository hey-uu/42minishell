/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:54:11 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/11 14:47:24 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	parse_command(t_node *node, t_token *token, int *offset)
{
	int	res;

	if (token[*offset].type == TOKEN_LPAREN)
		res = parse_subshell(node, token, offset);
	else
		res = parse_simple_command(node, token, offset);
	return (res);
}

int	parse_pipeline(t_node *node, t_token *token, int *offset)
{
	t_node	*cur_node;

	node->type = NODE_PIPELINE;
	node->first_child = create_tree_node();
	if (!parse_command(node->first_child, token, offset))
		return (SYNTAX_ERROR);
	cur_node = node->first_child;
	while (token[*offset].type == TOKEN_PIPE)
	{
		*offset += 1;
		cur_node->next_sibling = create_tree_node();
		if (!parse_command(cur_node->next_sibling, token, offset))
			return (SYNTAX_ERROR);
	}
	return (SYNTAX_OK);
}
