/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subshell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:56:31 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/26 17:33:36 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager.h"
#include "parser.h"

static int	subshell_parenthesis(t_node *node, t_token *tokens, int *offset)
{
	if (tokens[*offset].type != TOKEN_LPAREN)
		return (FAILURE);
	(*offset)++;
	node->first_child = create_tree_node();
	if (parse_list(&node->first_child, tokens, offset) == FAILURE)
		return (FAILURE);
	if (tokens[*offset].type != TOKEN_RPAREN)
		return (FAILURE);
	(*offset)++;
	return (SUCCESS);
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
			return (FAILURE);
		if (heredoc_stat_get() == HEREDOC_INTSIG)
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
