/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:49:25 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/11 00:53:56 by hyeyukim         ###   ########.fr       */
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

#endif