/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:33:26 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/26 17:33:36 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "error.h"
#include "env_manager.h"

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

	if (*errcode)
		return ;
	heredoc_init();
	*parse_tree = create_tree_node();
	if (tokens[0].type == TOKEN_NONE)
	{
		(*parse_tree)->type = NODE_NONE;
		return ;
	}
	offset = 0;
	res = parse_list(parse_tree, tokens, &offset);
	if (heredoc_stat_get() == HEREDOC_INTSIG)
	{
		*errcode = ERROR_HEREDOC_INTERUPTED;
		return ;
	}
	if (res == FAILURE || tokens[offset].type != TOKEN_NONE)
	{
		*syntax_error_near_token = tokens[offset];
		*errcode = ERROR_IN_SYNTAX;
	}
}
