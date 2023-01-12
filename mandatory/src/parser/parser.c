/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:33:26 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/12 21:38:59 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"
#include "error.h"

int	is_redirection(int type)
{
	if (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_IN_HERE || \
		type == TOKEN_REDIR_OUT || type == TOKEN_REDIR_OUT_APP)
		return (1);
	return (0);
}


void	destroy_token(t_token *token)
{
	int	i;

	i = -1;
	while (token[++i].type != TOKEN_NONE)
	{
		if (token[i].type == TOKEN_WORD)
			free(token[i].str);
	}
	free(token);
}

t_node	*parser(t_token *token)
{
	t_node	*parse_tree;
	int		res;
	int		offset;

	parse_tree = create_tree_node();
	offset = 0;
	res = parse_list(&parse_tree, token, &offset);
	if (res == SYNTAX_ERROR || token[offset].type != TOKEN_NONE)
	{
		print_syntax_error_message(token[offset].type, token[offset].str);
		destroy_token(token);
		destroy_tree(parse_tree);
		return (NULL);
	}
	destroy_token(token);
	return (parse_tree);
}
