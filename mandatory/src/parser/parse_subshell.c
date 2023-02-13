/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subshell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:56:31 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/28 21:04:39 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal.h"

static int	subshell_parenthesis(t_node *node, t_token *tokens, int *offset)
{
	if (tokens[*offset].type != TOKEN_LPAREN)
		return (FAILURE);
	(*offset)++;
	node->first_child = create_tree_node(NULL);
	node->first_child->root = &(node->first_child);
	if (parse_list(node->first_child, tokens, offset) == FAILURE)
		return (FAILURE);
	if (tokens[*offset].type != TOKEN_RPAREN)
		return (FAILURE);
	(*offset)++;
	return (SUCCESS);
}

static int	subshell_redirect_list(t_node *node, t_token *tokens, int *offset)
{
	t_queue	*q_redir_list;

	node->exe_unit = create_execute_unit(node->type);
	q_redir_list = node->exe_unit->q_redir_list;
	while (is_redirection(tokens[*offset].type))
	{
		(*offset)++;
		if (!((tokens[*offset].type == TOKEN_WORD)
				&& push_redirect(q_redir_list, tokens, *offset - 1) == SUCCESS))
			return (FAILURE);
		(*offset)++;
	}
	return (SUCCESS);
}

int	parse_subshell(t_node *node, t_token *tokens, int *offset)
{
	node->type = NODE_SUBSHELL;
	if (subshell_parenthesis(node, tokens, offset) == FAILURE)
		return (FAILURE);
	if (subshell_redirect_list(node, tokens, offset) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
