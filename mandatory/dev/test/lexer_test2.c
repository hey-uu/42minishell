/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_test2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:00:37 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/12 11:45:26 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

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
	int		res_token_cnt;
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