/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 08:05:41 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 03:38:27 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_INTERNAL_H
# define LEXER_INTERNAL_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "s_token.h"
# include "constants.h"
# include "handle_error.h"

/*-------------- FUNCTION PROTOTYPES -------------*/

t_token	extract_word_token(char **input);
t_token	extract_operator_token(char **input, const int token_type);

int		length_of_word(const char *input);
int		length_of_operator(const int token_type);

void	destroy_token_list(t_token *token_list);

/* utils for lexer */
int		get_token_type(const char *input);
int		is_blank(const char c);

#endif
