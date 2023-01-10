/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:33:23 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/10 18:50:07 by hyeyukim         ###   ########.fr       */
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

static int	is_blank(const char c)
{
	return (c == ' ' || c == '\t');
}

static int	get_token_type(const char *input)
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
	else if (*input == '\0')
		return (TOKEN_NONE);
	else
		return (TOKEN_WORD);
}

static int	length_operator(const int token_type)
{
	if (token_type == TOKEN_AND_IF \
		|| token_type == TOKEN_OR_IF \
		|| token_type == TOKEN_REDIR_IN_HERE \
		|| token_type == TOKEN_REDIR_OUT_APP)
		return (2);
	else
		return (1);
}

static int	length_word(const char *input)
{
	int	len;
	int	quote;

	len = 0;
	quote = 0;
	while (input[len] && (quote || \
		(!is_blank(input[len]) && get_token_type(&input[len]) == TOKEN_WORD)))
	{
		if (!quote && (input[len] == '\'' || input[len] == '\"'))
			quote = input[len];
		else if (quote && input[len] == quote)
			quote = 0;
		len++;
	}
	if (quote)
	{
		printf("syntax error: unclosed quote\n");
		exit(1);
	}
	return (len);
}

static int	count_tokens(const char *input)
{
	int	cnt;
	int	cur_token_type;

	cnt = 0;
	while (*input)
	{
		while (is_blank(*input))
			input++;
		cur_token_type = get_token_type(input);
		if (cur_token_type == TOKEN_NONE)
			break ;
		else if (cur_token_type == TOKEN_WORD)
			input += length_word(input);
		else
			input += length_operator(cur_token_type);
		cnt++;
	}
	return (cnt);
}

static t_token	extract_word_token(char **input)
{
	t_token		token;
	const int	word_len = length_word(*input);

	token.type = TOKEN_WORD;
	token.str = ft_substr(*input, 0, word_len);
	*input += word_len;
	return (token);
}

static t_token extract_operator_token(char **input, const int token_type)
{
	t_token	token;

	token.type = token_type;
	token.str = NULL;
	*input += length_operator(token_type);
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
// 	// printf("%d\n", length_word("\'\"hi\"\' \"a&&dfa\""));
// 	// printf("%d\n", count_tokens("   \"echo    \"aa&&    echo gg|cat&& echo   ss "));
// 	// print_token_list(lexer("   \"echo    \"aa&&    echo gg|cat&& echo   ss "));
// 	print_token_list(lexer(" \" \' \'\" \""));
// 	return 0;
// }

