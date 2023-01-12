/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simple_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:56:36 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/13 04:44:15 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	parse_prefix(t_execute_unit *exe_unit, t_token *tokens, int *offset)
{
	while (is_redirection(tokens[*offset].type))
	{
		(*offset)++;
		if (tokens[*offset].type == TOKEN_WORD)
			push_redirection(exe_unit->redir_list, tokens, *offset - 1);
		else
			return (SYNTAX_ERROR);
		(*offset)++;
	}
	return (SYNTAX_OK);
}

static int	parse_command_name(\
			t_execute_unit *exe_unit, t_token *tokens, int *offset)
{
	if (tokens[*offset].type == TOKEN_WORD)
	{
		exe_unit->cmd_name = ft_strdup(tokens[*offset].str);
		push_arguments(exe_unit->cmd_argv, tokens, *offset);
		(*offset)++;
	}
	return (SYNTAX_OK);
}

static int	parse_suffix(t_execute_unit *exe_unit, t_token *tokens, int *offset)
{
	while (1)
	{
		if (tokens[*offset].type == TOKEN_WORD)
		{
			push_arguments(exe_unit->cmd_argv, tokens, *offset);
			(*offset)++;
		}
		else if (is_redirection(tokens[*offset].type))
		{
			(*offset)++;
			if (tokens[*offset].type == TOKEN_WORD)
				push_redirection(exe_unit->redir_list, tokens, *offset - 1);
			else
				return (SYNTAX_ERROR);
			(*offset)++;
		}
		else
			break ;
	}
	return (SYNTAX_OK);
}

int	parse_simple_command(t_node *node, t_token *tokens, int *offset)
{
	const int	initial_offset = *offset;

	node->type = NODE_SIMPLE_CMD;
	node->exe_unit = create_execute_unit(node->type);
	if (parse_prefix(node->exe_unit, tokens, offset) == SYNTAX_ERROR)
		return (SYNTAX_ERROR);
	parse_command_name(node->exe_unit, tokens, offset);
	if (parse_suffix(node->exe_unit, tokens, offset) == SYNTAX_ERROR)
		return (SYNTAX_ERROR);
	if (*offset == initial_offset)
		return (SYNTAX_ERROR);
	return (SYNTAX_OK);
}
