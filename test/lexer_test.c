/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:00:37 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/10 22:27:21 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

// tests

#define TEST_NUM 20

char	*test_cases[TEST_NUM] = {\
//1
	"echo hello | xargs echo | ls -l", \
//2
	"ls -al && echo a", \
//3
	"ls | ls | ls || ls", \
//4
	"(sleep 3) && echo 3", \
//5
	"ls | &e && echo 3", \
//6
	"&&& && echo 3", \
//7
	"321 && echo 3", \
//8
	"   echo aa&&    echo gg|cat&& echo   ss", \
//9
	"|||||", \
// 10
	"ls -al -l -a -d -a -f (********()", \
//11
	"cd .. && cat < file && echo hello >> output &&&a |cat<<here_&&doc", \
//12
	"", \
//13
	"\'       A\'ZCV", \
//14
	"\"        hihi  |  a\" | ",\
//15
	"\'\"hihihihihihi\"\' \"a&&dfa\"",\
//16
	"\'\'\"\'\'\'\"",\
//17
	"\'a\' \'b\' \"c\'\" &|&||",\
//18
	"\"\'\"",\
//19
	"\'abc\'  && \"adfa$&&||\"",\
//20(syntax error)
	"\'\"\"ADFADF"
};

int	counts[TEST_NUM] = {\
//1
	8, \
// 2
	5, \
// 3
	7, \
// 4
	7, \
// 5
	6, \
// 6
	5, \
// 7
	4, \
// 8
	10, \
// 9
	3, \
// 10
	11, \
// 11
	19, \
// 12
	0, \
// 13
	1, \
// 14
	2, \
// 15
	2, \
// 16
	1, \
// 17
	7, \
// 18
	1, \
// 19
	3, \
// 20
	0
};

int	tokens[TEST_NUM][100] = {\
//1
	{TOKEN_WORD, TOKEN_WORD, TOKEN_PIPE, TOKEN_WORD, TOKEN_WORD, TOKEN_PIPE, \
	TOKEN_WORD, TOKEN_WORD, TOKEN_NONE},\
//2
	{TOKEN_WORD, TOKEN_WORD, TOKEN_AND_IF, TOKEN_WORD, TOKEN_WORD, TOKEN_NONE},\
//3
	{TOKEN_WORD, TOKEN_PIPE, TOKEN_WORD, TOKEN_PIPE, TOKEN_WORD, TOKEN_OR_IF, \
	TOKEN_WORD, TOKEN_NONE},\
//4
	{TOKEN_LPAREN, TOKEN_WORD, TOKEN_WORD, TOKEN_RPAREN, TOKEN_AND_IF, TOKEN_WORD, \
	TOKEN_WORD, TOKEN_NONE},\
//5
	{TOKEN_WORD, TOKEN_PIPE, TOKEN_WORD, TOKEN_AND_IF, TOKEN_WORD, TOKEN_WORD, \
	TOKEN_NONE}, \
//6
	{TOKEN_AND_IF, TOKEN_WORD, TOKEN_AND_IF, TOKEN_WORD, TOKEN_WORD, TOKEN_NONE}, \
//7
	{TOKEN_WORD, TOKEN_AND_IF, TOKEN_WORD, TOKEN_WORD, TOKEN_NONE}, \
//8
	{TOKEN_WORD, TOKEN_WORD, TOKEN_AND_IF, TOKEN_WORD, TOKEN_WORD, TOKEN_PIPE, \
	TOKEN_WORD, TOKEN_AND_IF, TOKEN_WORD, TOKEN_WORD, TOKEN_NONE},\
//9
	{TOKEN_OR_IF, TOKEN_OR_IF, TOKEN_PIPE, TOKEN_NONE}, \
//10
	{TOKEN_WORD, TOKEN_WORD, TOKEN_WORD, TOKEN_WORD, TOKEN_WORD, TOKEN_WORD, \
	TOKEN_WORD, TOKEN_LPAREN, TOKEN_WORD, TOKEN_LPAREN, TOKEN_RPAREN, TOKEN_NONE},\
//11
	{TOKEN_WORD, TOKEN_WORD, TOKEN_AND_IF, TOKEN_WORD, TOKEN_REDIR_IN, TOKEN_WORD, \
	TOKEN_AND_IF, TOKEN_WORD, TOKEN_WORD, TOKEN_REDIR_OUT_APP, TOKEN_WORD, TOKEN_AND_IF,\
	TOKEN_WORD, TOKEN_PIPE, TOKEN_WORD, TOKEN_REDIR_IN_HERE, TOKEN_WORD, TOKEN_AND_IF,\
	TOKEN_WORD, TOKEN_NONE},\
//12
	{TOKEN_NONE},\
//13
	{TOKEN_WORD, TOKEN_NONE},\
//14
	{TOKEN_WORD, TOKEN_PIPE, TOKEN_NONE},\
//15
	{TOKEN_WORD, TOKEN_WORD, TOKEN_NONE},\
//16
	{TOKEN_WORD, TOKEN_NONE},\
//17
	{TOKEN_WORD, TOKEN_WORD, TOKEN_WORD, TOKEN_WORD, TOKEN_PIPE, TOKEN_WORD, TOKEN_OR_IF, TOKEN_NONE},\
//18
	{TOKEN_WORD, TOKEN_NONE},\
//19
	{TOKEN_WORD, TOKEN_AND_IF, TOKEN_WORD, TOKEN_NONE},\
//20
	{TOKEN_ERROR}
};

int	main(void)
{
	int		i, j;
	int		res_token_cnt;
	t_token	*res_tokens;

	i = -1;
	while (++i < TEST_NUM)
	{
		printf("\n=================================================================\n");
		printf("%dth test\n", i + 1);
		printf("	::test case : [%s]\n", test_cases[i]);
		res_token_cnt = count_tokens(test_cases[i]);
		printf("	::token counts : %d\n", res_token_cnt);
		assert(counts[i] == res_token_cnt);
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
		printf("=================================================================\n");
	}
}