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

static int	parse_command(t_node *node, t_token *tokens, int offset)
{
	int	res;

	if (tokens[offset].type == TOKEN_LPAREN)
		res = parse_subshell(node, tokens, offset);
	else
		res = parse_simple_command(node, tokens, offset);
	return (res);
}

int	parse_pipeline(t_node *node, t_token *tokens, int offset)
{
	t_node	*cur_node;
	int		cnt;
	int		res;

	node->type = NODE_PIPELINE;
	node->first_child = create_tree_node();
	res = parse_command(node->first_child, tokens, offset);
	if (!res)
		return (0);
	cnt = res;
	cur_node = node->first_child;
	while (tokens[offset + cnt].type == TOKEN_PIPE)
	{
		cnt++;
		cur_node->next_sibling = create_tree_node();
		res = parse_command(cur_node->next_sibling, tokens, offset + cnt);
		if (!res)
			return (0);
		cnt += res;
	}
	return (cnt);
}