/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subshell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:56:31 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/12 20:16:09 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	subshell_parenthesis(t_node *node, t_token *token, int *offset)
{
	if (token[*offset].type != TOKEN_LPAREN)
		return (SYNTAX_ERROR);
	(*offset)++;
	node->first_child = create_tree_node();
	if (!parse_list(&node->first_child, token, offset))
		return (SYNTAX_ERROR);
	if (token[*offset].type != TOKEN_RPAREN)
		return (SYNTAX_ERROR);
	(*offset)++;
	return (SYNTAX_OK);
}

static int	subshell_redirect_list(t_node *node, t_token *token, int *offset)
{
	node->exe_unit = create_execute_unit(node->type);
	while (is_redirection(token[*offset].type))
	{
		(*offset)++;
		if (token[*offset].type == TOKEN_WORD)
			push_redirection(node->exe_unit->redir_list, token, *offset - 1);
		else
			return (SYNTAX_ERROR);
		(*offset)++;
	}
	return (SYNTAX_OK);
}

int	parse_subshell(t_node *node, t_token *token, int *offset)
{
	node->type = NODE_SUBSHELL;
	if (!subshell_parenthesis(node, token, offset))
		return (SYNTAX_ERROR);
	if (!subshell_redirect_list(node, token, offset))
		return (SYNTAX_ERROR);
	return (SYNTAX_OK);
}
