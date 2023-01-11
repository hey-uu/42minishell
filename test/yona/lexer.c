/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:33:23 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/07 19:08:47 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// control operator (제어 연산자)
	// : 제어 함수를 실행하는 토큰.  개행이나 다음 중 하나입니다.
	//  → ::, &&, &, ;, ;;, ;&, ;;&, |, |&, (, ).
// redirection operator (리다이렉션 연산자)
	// : >, >>, , <<

// token 리스트 처음부터 끝까지 출력하는 함수 (debug용)
#include <stdio.h>
void	print_token_list(t_token *list)
{
	int i = 0;
	while (list[i].type != TOKEN_NONE)
	{
		printf("%d: type %d %s\n", i, list[i].type, list[i].str);
		i++;
	}
}

// 현재 포인터 위치의 문자가 blank이면 str 포인터를 한칸 이동시킴
// 반환값 : blank가 있으면 1, blank가 없으면 0
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
		while (*str && !skip_blank(&str) && !skip_operator(&str))
		{
			str += 1;
			if (!flag)
				cnt++;
			flag = 1;
		}
	}
	return (cnt);
}

//   echo aa&&    echo gg|cat&& echo   ss
// -> echo, aa, &&, echo, gg, |, cat, &&, echo, ss

// 우리의 쉘에서 & 하나만 있는 경우는 다루지 않음.
	// 즉 echo aa&| echo gg|cat&& echo ss인 경우
	// -> echo, aa&, |, echo, gg, |, cat, &&, echo, ss


int is_blank(char c)
{
	return (c == ' ' || c == '\t');
}

int	get_token_type(char *input)
{
	if (*input == '(')
		return (TOKEN_LPAREN);
	else if (*input == ')')
		return (TOKEN_RPAREN);
	else if (*input == '&' && *(input + 1) == '&')
		return (TOKEN_AND_IF);
	else if (*input == '|' && *(input + 1) == '|')
		return (TOKEN_OR_IF);
	else if (*input == '>' && *(input + 1) == '>')
		return (TOKEN_REDIR_OUT_APP);
	else if (*input == '<' && *(input + 1) == '<')
		return (TOKEN_REDIR_IN_HERE);
	else if (*input == '|')
		return (TOKEN_PIPE);
	else if (*input == '<')
		return (TOKEN_REDIR_IN);
	else if (*input == '>')
		return (TOKEN_REDIR_OUT);
	else
		return (TOKEN_WORD);
}

t_token	extract_word_token(char **input)
{
	t_token	token;
	int		word_len;

	word_len = 0;
	while (!is_blank((*input)[word_len]) && \
		get_token_type(&(*input)[word_len]) == TOKEN_WORD)
		word_len++;
	token.str = ft_substr(*input, 0, word_len);
	token.type = TOKEN_WORD;
	*input += word_len;
	return (token);
}

t_token extract_operator_token(char **input, int token_type)
{
	t_token	token;
	int		op_len;

	if (token_type == TOKEN_AND_IF \
		|| token_type == TOKEN_OR_IF \
		|| token_type == TOKEN_REDIR_IN_HERE \
		|| token_type == TOKEN_REDIR_OUT_APP)
		op_len = 2;
	else
		op_len = 1;
	token.type = token_type;
	*input += op_len;
	return (token);
}

t_token	*lexer(char *input)
{
	t_token	*token_list;
	int		token_cnt;
	int		cur_token_type;
	int		i;

	token_cnt = count_tokens(input);
	token_list = malloc(sizeof(t_token) * (token_cnt + 1));
	i = 0;
	while (i < token_cnt)
	{
		while (is_blank(*input))
			input++;
		cur_token_type = get_token_type(input);
		if (get_token_type(input) == TOKEN_WORD)
			token_list[i] = extract_word_token(&input);
		else
			token_list[i] = extract_operator_token(&input, cur_token_type);
		i++;
	}
	token_list[token_cnt].type = TOKEN_NONE;
	return (token_list);
}

#include <stdio.h>
int main()
{
	printf("%d\n", count_tokens("   echo aa&&    echo gg|cat&& echo   ss"));
	// print_token_list(lexer("   echo aa&&    echo gg|cat&& echo   ss"));
	return 0;
}

