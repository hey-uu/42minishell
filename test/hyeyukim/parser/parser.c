/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:33:26 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/10 23:52:55 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"

void	print_syntax_error_message(t_token *token)
{
	static char	*token_str[11] = {"\n", 0, "(", ")", "&&", "||", \
								"|", "<", ">", "<<", ">>"};

	printf("goldsh: syntax error near unexpected token ");
	if (token->type == TOKEN_WORD)
		printf("'%s'\n", token->str);
	else
		printf("'%s'\n", token_str[token->type]);
}

t_node	*parser(t_token *tokens)
{
	t_node	*parse_tree;
	int		token_num;

	parse_tree = create_tree_node();
	token_num = parse_list(&parse_tree, tokens, 0);
	free(tokens);
	if (tokens[token_num].type != TOKEN_NONE)
	{
		print_syntax_error_message(&tokens[token_num]);
		destroy_tree(parse_tree);
		return (NULL);
		//error 처리
		// error 문구는 : tokens[token_num - 1].str 토큰을 사용할 것
	}
	return (parse_tree);
}
