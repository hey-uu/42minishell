#include <stdio.h>
#include "../inc/mandatory/minishell.h"


// gcc count_tokens.c -I../lib/libft/includes

int	skip_blank(char **str)
{
	const int	c = **str;

	if (c == ' ' || c == '\t' || c == '\n')
		*str += 1;
	else
		return (0);
	return (1);
}

// 현재 포인터 위치의 문자가 operator이면 operator 길이만큼 이동시킴
// 반환값 : operator가 있으면 1, 없으면 0
int	skip_operator(char **str)
{
	const char	first = **str;
	const char	second = *(*str + 1);

	if ((first == '&' && second == '&') || (first == '|' && second == '|') ||\
		(first == '<' && second == '<') || (first == '>' && second == '>'))
		*str += 2;
	else if (first == '|' || first == '<' || first == '>' || \
			first == '(' || first == ')')
		*str += 1;
	else
		return (0);
	return (1);
}

int	count_tokens(char *str)
{
	int	cnt;
	int	flag;

	cnt = 0;
	while (*str)
	{
		flag = 0;
		while (*str && skip_blank(&str))
			;
		if (*str && skip_operator(&str))
			cnt++;
		while (*str && !skip_blank(&str))
		{
			if (!skip_operator(&str))
			{
				str += 1; 
				if (!flag)
					cnt++;
				flag = 1;
			}
			else
				cnt++;
		}
	}
	return (cnt);
}


#include <stdio.h>
#include <assert.h>
// tests
# define TEST_CASES 4
# define TEST0 "echo hello | xargs echo | ls -l"
# define TEST0_ANS 8
# define TEST1 "ls -al && echo a" //5
# define TEST1_ANS 5
# define TEST2 "ls | ls | ls || ls" //7
# define TEST2_ANS 7
# define TEST3 "(sleep 3) && echo 3" //7
# define TEST3_ANS 7
# define TEST4 "ls | &e && echo 3" //6
# define TEST4_ANS 6
# define TEST5 "&&& && echo 3" //5
# define TEST5_ANS 5
# define TEST6 "321 && echo 3" //4
# define TEST6_ANS 4
# define TEST7 "   echo aa&&    echo gg|cat&& echo   ss"
# define TEST7_ANS 10

// test function
# define TEST(i) \
printf("\n====================\n");\
printf("%dth test\n", i);\
assert(count_tokens(TEST##i) == TEST##i##_ANS);\
printf("---> ok\n");\
printf("====================\n");\
// printf("my counter: %d\n", count_tokens(TEST##i));\
// printf("the answer: %d\n", TEST##i##_ANS); \

// main
int main()
{
	int	i;

	TEST(0);
	TEST(1);
	TEST(2);
	TEST(3);
	TEST(4);
	TEST(5);
	TEST(6);
	TEST(7);
}

