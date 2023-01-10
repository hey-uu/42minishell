/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simple_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:56:36 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/11 02:06:45 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include "parser.h"

static t_simple_cmd	*create_simple_command(void)
{
	t_simple_cmd	*new;

	new = ft_malloc(sizeof(t_simple_cmd));
	new->name = NULL;
	new->argv = create_queue(QUEUE_INITIAL_SIZE, QUEUE_STR_ONLY);
	return (new);
}

static int	parse_suffix(t_execute_unit *unit, t_token *token, int *offset)
{
	while (1)
	{
		if (token[*offset].type == TOKEN_WORD)
		{
			push_arguments(unit->simple_cmd, token, *offset);
			*offset += 1;
		}
		else if (is_redirection(token[*offset].type))
		{
			*offset += 1;
			if (token[*offset].type == TOKEN_WORD)
				push_redirection(unit->io_list, token, *offset - 1);
			else
				return (SYNTAX_ERROR);
			*offset += 1;
		}
		else
			break ;
	}
	return (SYNTAX_NORMAL);
}

static int	parse_prefix(t_redir_list *io_list, t_token *token, int *offset)
{
	while (is_redirection(token[*offset].type))
	{
		*offset += 1;
		if (token[*offset].type == TOKEN_WORD)
			push_redirection(io_list, token, *offset - 1);
		else
			return (SYNTAX_ERROR);
		*offset += 1;
	}
	return (SYNTAX_NORMAL);
}

static int	parse_command_name(\
			t_simple_cmd *simple_cmd, t_token *token, int *offset)
{
	if (token[*offset].type == TOKEN_WORD)
	{
		simple_cmd->name = ft_strdup(token[*offset].str);
		push_arguments(simple_cmd, token, *offset);
		*offset += 1;
	}
	return (SYNTAX_NORMAL);
}

int	parse_simple_command(t_node *node, t_token *token, int *offset)
{
	const int	initial_offset = *offset;

	node->type = NODE_SIMPLE_CMD;
	node->exe_unit.simple_cmd = create_simple_command();
	node->exe_unit.io_list = create_redirect_list();
	if (!parse_prefix(node->exe_unit.io_list, token, offset))
		return (SYNTAX_ERROR);
	parse_command_name(node->exe_unit.simple_cmd, token, offset);
	if (!parse_suffix(&node->exe_unit, token, offset))
		return (SYNTAX_ERROR);
	if (*offset == initial_offset)
		return (SYNTAX_ERROR);
	return (SYNTAX_NORMAL);
}
