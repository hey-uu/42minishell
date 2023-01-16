/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_token.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:58:22 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 23:00:19 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TOKEN_H
# define T_TOKEN_H

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

enum e_success_or_failure
{
	FAILURE = -1,
	SUCCESS = 0
};

/*------------- STRUCT DECLARATIONS --------------*/

typedef struct s_token
{
	int		type;
	char	*str;
}	t_token;

#endif