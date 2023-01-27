/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:33:26 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 20:23:17 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_error.h"
#include "heredoc_manager.h"
#include "parser_internal.h"

int	parser(t_token *tokens, t_node **parse_tree)
{
	int		res;
	int		offset;

	*parse_tree = create_tree_node(parse_tree);
	if (tokens[0].type == TOKEN_NONE)
	{
		(*parse_tree)->type = NODE_NONE;
		return (SUCCESS);
	}
	offset = 0;
	heredoc_init(*parse_tree);
	res = parse_list(*parse_tree, tokens, &offset);
	if (heredoc_stat_get() == HEREDOC_INTSIG)
	{
		return (FAILURE);
	}
	if (res == FAILURE || tokens[offset].type != TOKEN_NONE)
	{
		handle_syntax_error(tokens[offset]);
		return (FAILURE);
	}
	return (SUCCESS);
}
