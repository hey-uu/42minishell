/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:04:48 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 20:04:54 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_internal.h"

int	get_token_type(const char *input)
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
