/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:33:23 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/07 22:02:51 by yeonhkim         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (list[i].type != TOKEN_NONE)
	{
		printf("%d: type %d %s\n", i, list[i].type, list[i].str);
		i++;
	}
}

int	is_blank(char c)
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

int	operator_length(int token_type)
{
	if (token_type == TOKEN_AND_IF \
		|| token_type == TOKEN_OR_IF \
		|| token_type == TOKEN_REDIR_IN_HERE \
		|| token_type == TOKEN_REDIR_OUT_APP)
		return (2);
	else
		return (1);
}

// 현재 가리키고 있는게 끝이 아니고, 
	// 따옴표가 아직 닫히지 않았거나 혹은
	// (blank가 아님 && 토큰 타입 워드)인 경우 word의 부분인 것으로 판단
int	word_length(char *input)
{
	int	len;
	int	quote;

	len = 0;
	quote = 0;
	while (input[len] && (quote || \
	(!is_blank(input[len]) && get_token_type(&input[len]) == TOKEN_WORD)))
	{
		if (quote && input[len] == quote)
			quote = 0;
		else if (!quote && (input[len] == '\'' || input[len] == '\"'))
			quote = input[len];
		len++;
	}
	if (quote)
	{
		printf("syntax error: unclosed quote\n");
		exit(1);
	}
	return (len);
}

int	count_tokens(char *input)
{
	int	cnt;
	int	cur_token_type;

	cnt = 0;
	while (is_blank(*input))
			input++;
	while (*input)
	{
		cur_token_type = get_token_type(input);
		if (cur_token_type == TOKEN_WORD)
			input += word_length(input);
		else
			input += operator_length(cur_token_type);
		while (is_blank(*input))
			input++;
		cnt++;
	}
	return (cnt);
}

t_token	extract_word_token(char **input)
{
	t_token	token;
	int		word_len;

	word_len = word_length(*input);
	token.str = ft_substr(*input, 0, word_len);
	token.type = TOKEN_WORD;
	*input += word_len;
	return (token);
}

t_token extract_operator_token(char **input, int token_type)
{
	t_token	token;

	token.type = token_type;
	token.str = NULL;
	*input += operator_length(token_type);
	return (token);
}

t_token	*lexer(char *input)
{
	t_token	*token_list;
	int		cur_token_type;
	int		token_cnt;
	int		i;

	token_cnt = count_tokens(input);
	token_list = malloc(sizeof(t_token) * (token_cnt + 1));
	i = 0;
	while (i < token_cnt)
	{
		while (is_blank(*input))
			input++;
		cur_token_type = get_token_type(input);
		if (cur_token_type == TOKEN_WORD)
			token_list[i] = extract_word_token(&input);
		else
			token_list[i] = extract_operator_token(&input, cur_token_type);
		i++;
	}
	token_list[token_cnt].type = TOKEN_NONE;
	return (token_list);
}

// #include <stdio.h>
// int main()
// {
// 	// printf("%d\n", count_tokens("   ss"));
// 	// printf("%d\n", word_length("\'\"hi\"\' \"a&&dfa\""));
// 	// printf("%d\n", count_tokens("   \"echo    \"aa&&    echo gg|cat&& echo   ss "));
// 	// print_token_list(lexer("  \'\"hihihihihihi\"\'\' \"a&&dfa\""));
// 	// print_token_list(lexer(" \" \' \" \""));
// 	return 0;
// }

