/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simple_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:56:36 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/10 23:24:26 by hyeyukim         ###   ########.fr       */
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

static int	parse_suffix(t_execute_unit *unit, t_token *token, int offset)
{
	int	cnt;

	cnt = 0;
	while (1)
	{
		if (token[offset + cnt].type == TOKEN_WORD)
		{
			push_arguments(unit->simple_cmd, token, offset + cnt);
			cnt++;
		}
		else if (is_redirection(token[offset + cnt].type))
		{
			if (token[offset + cnt + 1].type == TOKEN_WORD)
				push_redirection(unit->io_list, token, offset + cnt);
			else
				return (-1);
			cnt += 2;
		}
		else
			break ;
	}
	return (cnt);
}

static int	parse_prefix(t_redir_list *io_list, t_token *token, int offset)
{
	int	cnt;

	cnt = 0;
	while (is_redirection(token[offset + cnt].type))
	{
		if (token[offset + cnt + 1].type == TOKEN_WORD)
			push_redirection(io_list, token, offset + cnt);
		else
			return (-1);
		cnt += 2;
	}
	return (cnt);
}

static int	parse_command_name(t_simple_cmd *simple_cmd, t_token *token, int offset)
{
	if (token[offset].type == TOKEN_WORD)
	{
		simple_cmd->name = token[offset].str;
		push_arguments(simple_cmd, token, offset);
		return (1);
	}
	return (0);
}

int	parse_simple_command(t_node *node, t_token *token, int offset)
{
	int	res[3];

	node->type = NODE_SIMPLE_CMD;
	node->exe_unit.simple_cmd = create_simple_command();
	node->exe_unit.io_list = create_redirect_list();
	res[0] = parse_prefix(node->exe_unit.io_list, token, offset);
	if (res[0] == -1)
		return (0);
	res[1] = parse_command_name(\
			node->exe_unit.simple_cmd, token, offset + res[0]);
	res[2] = parse_suffix(\
			&node->exe_unit, token, offset + res[0] + res[1]);
	if (res[2] == -1 || (res[0] + res[1] + res[2]) == 0)
		return (0);
	return (res[0] + res[1] + res[2]);
}
