/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_token.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:58:22 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 03:36:11 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_TOKEN_H
# define S_TOKEN_H

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum e_token_type
{
	TOKEN_NONE,
	TOKEN_WORD,
	TOKEN_LPAREN,
	TOKEN_RPAREN,
	TOKEN_AND_IF,
	TOKEN_OR_IF,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_IN_HERE,
	TOKEN_REDIR_OUT_APP
};

enum e_lexer_result_status
{
	LEXER_FAILURE = -1,
	LEXER_SUCCESS = 0
};

/*------------- STRUCT DECLARATIONS --------------*/

typedef struct s_token
{
	int		type;
	char	*str;
}	t_token;

#endif