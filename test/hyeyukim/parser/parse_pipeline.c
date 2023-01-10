/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:54:11 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/11 00:05:01 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	parse_command(t_node *node, t_token *tokens, int *offset)
{
	int	res;

	if (tokens[*offset].type == TOKEN_LPAREN)
		res = parse_subshell(node, tokens, offset);
	else
		res = parse_simple_command(node, tokens, offset);
	return (res);
}

int	parse_pipeline(t_node *parent, t_token *tokens, int *offset)
{
	t_node	*cur_node;
	int		res;

	parent->type = NODE_PIPELINE;
	parent->first_child = create_tree_node();
	if (!parse_command(parent->first_child, tokens, offset))
		return (0);
	cur_node = parent->first_child;
	while (tokens[*offset].type == TOKEN_PIPE)
	{
		offset++;
		cur_node->next_sibling = create_tree_node();
		if (!parse_command(cur_node->next_sibling, tokens, offset))
			return (0);
	}
	return (1);
}