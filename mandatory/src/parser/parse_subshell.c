/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subshell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:56:31 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/19 19:24:55 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	subshell_parenthesis(t_node *node, t_token *tokens, int *offset)
{
	if (tokens[*offset].type != TOKEN_LPAREN)
		return (SYNTAX_ERROR);
	(*offset)++;
	node->first_child = create_tree_node();
	if (parse_list(&node->first_child, tokens, offset) == SYNTAX_ERROR)
		return (SYNTAX_ERROR);
	if (tokens[*offset].type != TOKEN_RPAREN)
		return (SYNTAX_ERROR);
	(*offset)++;
	return (SYNTAX_OK);
}

static int	subshell_redirect_list(t_node *node, t_token *tokens, int *offset)
{
	node->exe_unit = create_execute_unit(node->type);
	while (is_redirection(tokens[*offset].type))
	{
		(*offset)++;
		if (tokens[*offset].type == TOKEN_WORD)
			push_redirection(node->exe_unit->q_redir_list, tokens, *offset - 1);
		else
			return (SYNTAX_ERROR);
		(*offset)++;
	}
	return (SYNTAX_OK);
}

int	parse_subshell(t_node *node, t_token *tokens, int *offset)
{
	node->type = NODE_SUBSHELL;
	if (subshell_parenthesis(node, tokens, offset) == SYNTAX_ERROR)
		return (SYNTAX_ERROR);
	if (subshell_redirect_list(node, tokens, offset) == SYNTAX_ERROR)
		return (SYNTAX_ERROR);
	return (SYNTAX_OK);
}
