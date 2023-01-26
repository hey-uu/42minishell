/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:33:26 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/26 22:54:07 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "error_handle.h"
#include "env_manager.h"

int	parser(t_token *tokens, t_node **parse_tree)
{
	int		res;
	int		offset;

	*parse_tree = create_tree_node();
	if (tokens[0].type == TOKEN_NONE)
	{
		(*parse_tree)->type = NODE_NONE;
		return (SUCCESS);
	}
	heredoc_init(*parse_tree);
	offset = 0;
	res = parse_list(parse_tree, tokens, &offset);
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
