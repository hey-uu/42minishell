/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simple_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:56:36 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/27 20:23:54 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser_internal.h"

static int	parse_prefix(t_queue *q_redir_list, t_token *tokens, int *offset)
{
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

static int	parse_command_name(
			t_execute_unit *exe_unit, t_token *tokens, int *offset)
{
	if (tokens[*offset].type == TOKEN_WORD)
	{
		exe_unit->cmd_name = ft_strdup(tokens[*offset].str);
		push_arguments(exe_unit->q_cmd_argv, tokens, *offset);
		(*offset)++;
	}
	return (SUCCESS);
}

static int	parse_suffix(t_queue *q_cmd_argv, t_queue *q_redir_list,
												t_token *tokens, int *offset)
{
	while (1)
	{
		if (tokens[*offset].type == TOKEN_WORD)
		{
			push_arguments(q_cmd_argv, tokens, *offset);
			(*offset)++;
		}
		else if (is_redirection(tokens[*offset].type))
		{
			(*offset)++;
			if (!((tokens[*offset].type == TOKEN_WORD) && push_redirect(\
					q_redir_list, tokens, *offset - 1) == SUCCESS))
				return (FAILURE);
			(*offset)++;
		}
		else
			break ;
	}
	return (SUCCESS);
}

int	parse_simple_command(t_node *node, t_token *tokens, int *offset)
{
	const int		initial_offset = *offset;

	node->type = NODE_SIMPLE_CMD;
	node->exe_unit = create_execute_unit(node->type);
	if (parse_prefix(node->exe_unit->q_redir_list, tokens, offset) == FAILURE)
		return (FAILURE);
	parse_command_name(node->exe_unit, tokens, offset);
	if (parse_suffix(node->exe_unit->q_cmd_argv, node->exe_unit->q_redir_list, \
					tokens, offset) == FAILURE)
		return (FAILURE);
	if (*offset == initial_offset)
		return (FAILURE);
	return (SUCCESS);
}
