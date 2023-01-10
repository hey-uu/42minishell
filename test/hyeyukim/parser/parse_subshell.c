/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subshell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:56:31 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/11 00:12:09 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse_subshell(t_node *node, t_token *tokens, int *offset)
{
	node->type = NODE_SUBSHELL;
	if (tokens[*offset].type != TOKEN_LPAREN)
		return (0);
	offset++;
	node->first_child = create_tree_node();
	if (!parse_list(&node->first_child, tokens, offset))
		return (0);
	if (tokens[*offset].type != TOKEN_RPAREN)
		return (0);
	offset++;
	node->exe_unit.io_list = create_redirect_list();
	while (is_redirection(tokens[*offset].type))
	{
		if (tokens[*offset + 1].type == TOKEN_WORD)
			push_redirection(node->exe_unit.io_list, tokens, *offset);
		else
			return (0);
		offset += 2;
	}
	return (1);
}
