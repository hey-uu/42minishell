/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subshell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:56:31 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/11 10:56:01 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse_subshell(t_node *node, t_token *token, int *offset)
{
	node->type = NODE_SUBSHELL;
	if (token[*offset].type != TOKEN_LPAREN)
		return (SYNTAX_ERROR);
	*offset += 1;
	node->first_child = create_tree_node();
	if (!parse_list(&node->first_child, token, offset))
		return (SYNTAX_ERROR);
	if (token[*offset].type != TOKEN_RPAREN)
		return (SYNTAX_ERROR);
	*offset += 1;
	node->exe_unit.redir_list = create_redirect_list();
	while (is_redirection(token[*offset].type))
	{
		*offset += 1;
		if (token[*offset].type == TOKEN_WORD)
			push_redirection(node->exe_unit.redir_list, token, *offset - 1);
		else
			return (SYNTAX_ERROR);
		*offset += 1;
	}
	return (SYNTAX_NORMAL);
}
