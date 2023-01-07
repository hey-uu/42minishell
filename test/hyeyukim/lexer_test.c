
#include "lexer_test.h"

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
//17(syntax error)
	"\'\"\"ADFADF",\
//18
	"\"\'\"",\
//19
	"\'abc\'  && \"adfa$&&||\"",\
//20
	"\'a\' \'b\' \"c\'\" &|&||"\
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
	1, \
// 13
	1, \
// 14
	2, \
// 15
	2, \
// 16
	0, \
// 17
	0, \
// 18
	0, \
// 19
	3, \
// 20
	7
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
	{TOKEN_NONE},\
//17
	{TOKEN_NONE},\
//18
	{TOKEN_NONE},\
//19
	{TOKEN_NONE},\
//20
	{TOKEN_NONE}
};

int	main(void)
{
	int		i, j;
	int		res_token_cnt;
	t_token	*res_tokens;

	i = -1;
	while (++i < TEST_NUM)
	{
		printf("\n====================\n");
		printf("%dth test\n", i);
		printf("	::test case : [%s]\n", test_cases[i]);
		res_token_cnt = count_tokens(test_cases[i]);
		printf("	::token counts : %d\n", res_token_cnt);
		assert(counts[i] == res_token_cnt);
		res_tokens = lexer(test_cases[i]);
		for (j = 0 ; j < counts[i] + 1 ; j++)
		{
			if (j != counts[i])
				printf("		::token: %s\n", res_tokens[j].str);
			printf("		::token type : result(%d) answer(%d)\n", \
			res_tokens[j].type, tokens[i][j]);
			assert(res_tokens[j].type == (t_token_type)tokens[i][j]);
		}
		printf("--> ok\n");
		printf("====================\n");
	}
}