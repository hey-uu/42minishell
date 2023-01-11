/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:49:25 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/12 02:37:33 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

/**
 * @brief Lexer
 * 
 */

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum e_token_type
{
	TOKEN_NONE = 0,
	TOKEN_WORD = 1,
	TOKEN_LPAREN = 2,
	TOKEN_RPAREN = 3,
	TOKEN_AND_IF = 4,
	TOKEN_OR_IF = 5,
	TOKEN_PIPE = 6,
	TOKEN_REDIR_IN = 7,
	TOKEN_REDIR_OUT = 8,
	TOKEN_REDIR_IN_HERE = 9,
	TOKEN_REDIR_OUT_APP = 10
};

# define FAILURE -1
# define SUCCESS 0

# define MISSING_QUOTE -1

/*------------- STRUCT DECLARATIONS --------------*/

	// int	str_len;
	// int	expansion_mask; 
	// 와일드카드, 달러 여부 체크하여 마스크로 기록
typedef struct s_token
{
	int		type;
	char	*str;
}	t_token;

/*-------------- FUNCTION PROTOTYPES -------------*/

t_token	*lexer(char *input);
void	print_token_list(t_token *list);
void	destroy_token_list(t_token *token_list);
t_token	extract_word_token(char **input);
t_token	extract_operator_token(char **input, const int token_type);
int		get_token_type(const char *input);
int		is_blank(const char c);
int		length_of_word(const char *input);
int		length_of_operator(const int token_type);

#endif
