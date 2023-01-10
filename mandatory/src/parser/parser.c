/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:33:26 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/10 16:09:05 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redirection(int type)
{
	if (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_IN_HERE || \
		type == TOKEN_REDIR_OUT || type == TOKEN_REDIR_OUT_APP)
		return (1);
	return (0);
}

t_node	*parser(t_token *tokens)
{
	t_node	*parse_tree;
	int		token_num;

	parse_tree = create_tree_node();
	token_num = parse_list(&parse_tree, tokens, 0);
	if (tokens[token_num].type != TOKEN_NONE)
	{
		//error 처리
		// error 문구는 : tokens[token_num - 1].str 토큰을 사용할 것
	}
	free(tokens);
	if (g_goldsh.syntax_error == NONE)
		return (parse_tree);
	else
	{
		// print_parse_error_message(g_goldsh.syntax_error);
		destroy_tree(parse_tree);
		return (NULL);
	}
}
