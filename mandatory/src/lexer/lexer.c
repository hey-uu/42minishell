/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:33:23 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 23:00:48 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	count_tokens(const char *input)
{
	int	cnt;
	int	cur_token_type;
	int	cur_word_length;

	cnt = 0;
	while (*input)
	{
		while (is_blank(*input))
			input++;
		cur_token_type = get_token_type(input);
		if (cur_token_type == TOKEN_NONE)
			break ;
		else if (cur_token_type == TOKEN_WORD)
		{
			cur_word_length = length_of_word(input);
			if (cur_word_length == SYNTAX_ERROR)
				return (SYNTAX_ERROR);
			input += cur_word_length;
		}
		else
			input += length_of_operator(cur_token_type);
		cnt++;
	}
	return (cnt);
}

static int	do_lexing(char *input, t_token *token_list, int token_cnt)
{
	int	i;
	int	cur_token_type;

	i = 0;
	while (i < token_cnt)
	{
		while (is_blank(*input))
			input++;
		cur_token_type = get_token_type(input);
		if (cur_token_type == TOKEN_WORD)
		{
			token_list[i] = extract_word_token(&input);
			if (!token_list[i].str)
			{
				token_list[i].type = TOKEN_NONE;
				return (LEXER_FAILURE);
			}
		}
		else
			token_list[i] = extract_operator_token(&input, cur_token_type);
		i++;
	}
	token_list[token_cnt].type = TOKEN_NONE;
	return (LEXER_SUCCESS);
}

t_token	*lexer(char *input)
{
	t_token	*token_list;
	int		token_cnt;

	token_cnt = count_tokens(input);
	if (token_cnt == SYNTAX_ERROR)
	{
		print_syntax_error_message(TOKEN_NONE, NULL);
		return (NULL);
	}
	token_list = malloc(sizeof(t_token) * (token_cnt + 1));
	if (!token_list || do_lexing(input, token_list, token_cnt) == LEXER_FAILURE)
	{
		destroy_token_list(token_list);
		return (NULL);
	}
	return (token_list);
}
