/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:56:40 by yona              #+#    #+#             */
/*   Updated: 2023/01/12 02:07:41 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include "lexer.h"

t_token	extract_word_token(char **input)
{
	t_token		token;
	const int	word_len = length_of_word(*input);

	token.type = TOKEN_WORD;
	token.str = ft_substr(*input, 0, word_len);
	*input += word_len;
	return (token);
}

t_token	extract_operator_token(char **input, const int token_type)
{
	t_token	token;

	token.type = token_type;
	token.str = NULL;
	*input += length_of_operator(token_type);
	return (token);
}
