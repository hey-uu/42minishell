/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_test2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:00:37 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/12 22:09:14 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "lexer.h"
#include "error.h"

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

void	check_token_counts(int i)
{
	int	res_token_cnt;

	res_token_cnt = count_tokens(test_cases[i]);
	printf("	::token counts : %d\n", res_token_cnt);
	assert(counts[i] == res_token_cnt);
}

int	main(void)
{
	int		i, j;
	t_token	*res_tokens;

	i = -1;
	while (++i < TEST_NUM)
	{
		printf("\n========================================================\n");
		printf("%dth test\n", i + 1);
		printf("	::test case : [%s]\n", test_cases[i]);
		check_token_counts(i);
		res_tokens = lexer(test_cases[i]);
		if (!res_tokens)
		{
			assert(tokens[i][0] == TOKEN_ERROR);
			continue ;
		}
		for (j = 0 ; j < counts[i] + 1 ; j++)
		{
			if (j != counts[i])
				printf("		::token: %s\n", res_tokens[j].str);
			printf("		::token type : result(%d) answer(%d)\n", \
			res_tokens[j].type, tokens[i][j]);
			assert(res_tokens[j].type == tokens[i][j]);
		}
		free(res_tokens);
		printf("--> ok\n");
		printf("========================================================\n");
	}
}