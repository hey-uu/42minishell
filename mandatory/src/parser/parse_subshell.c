/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_subshell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:56:31 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/10 16:24:38 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_subshell(t_node *node, t_token *tokens, int offset)
{
	int				cnt;
	int				res;

	cnt = 0;
	node->type = NODE_SUBSHELL;
	if (tokens[offset + cnt].type != TOKEN_LPAREN)
		return (0);
	cnt++;
	node->first_child = create_tree_node();
	res = parse_list(&node->first_child, tokens, offset + cnt);
	if (!res)
		return (0);
	cnt += res;
	if (tokens[offset + cnt].type != TOKEN_RPAREN)
		return (0);
	cnt++;
	node->exe_unit.io_list = create_redirect_list();
	while (is_redirection(tokens[offset + cnt].type))
	{
		if (tokens[offset + cnt + 1].type == TOKEN_WORD)
			push_redirection(node->exe_unit.io_list, tokens, offset);
		else
			return (0);
		cnt += 2;
	}
	return (cnt);
}
