/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:33:26 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/13 04:54:01 by hyeyukim         ###   ########.fr       */
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

t_node	*parser(t_token *tokens)
{
	t_node	*parse_tree;
	int		res;
	int		offset;

	parse_tree = create_tree_node();
	offset = 0;
	res = parse_list(&parse_tree, tokens, &offset);
	if (res == SYNTAX_ERROR || tokens[offset].type != TOKEN_NONE)
	{
		print_syntax_error_message(tokens[offset].type, tokens[offset].str);
		destroy_token_list(tokens);
		destroy_tree(parse_tree);
		return (NULL);
	}
	destroy_token_list(tokens);
	return (parse_tree);
}
