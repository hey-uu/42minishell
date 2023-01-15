/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:33:26 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/19 12:44:48 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "error.h"

int	is_redirection(int token_type)
{
	if (token_type == TOKEN_REDIR_IN || token_type == TOKEN_REDIR_IN_HERE || \
		token_type == TOKEN_REDIR_OUT || token_type == TOKEN_REDIR_OUT_APP)
		return (1);
	return (0);
}

void	parser(t_token *tokens, t_node **parse_tree, int *errcode, \
									t_token *syntax_error_near_token)
{
	int		res;
	int		offset;

	*parse_tree = create_tree_node();
	offset = 0;
	res = parse_list(parse_tree, tokens, &offset);
	if (res == SYNTAX_ERROR || tokens[offset].type != TOKEN_NONE)
	{
		*syntax_error_near_token = tokens[offset];
		*errcode = ERROR_IN_SYNTAX;
	}
}
