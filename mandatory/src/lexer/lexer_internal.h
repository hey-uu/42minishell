/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 08:05:41 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 20:04:15 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_INTERNAL_H
# define LEXER_INTERNAL_H

/**
 * @brief Lexer
 * 
 */

/*-------------- USER DEFINED HEADERS ------------*/

# include "s_token.h"
# include "constants.h"
# include "handle_error.h"

/*-------------- FUNCTION PROTOTYPES -------------*/

void	print_token_list(t_token *list);
void	destroy_token_list(t_token *token_list);
t_token	extract_word_token(char **input);
t_token	extract_operator_token(char **input, const int token_type);
int		get_token_type(const char *input);
int		is_blank(const char c);
int		length_of_word(const char *input);
int		length_of_operator(const int token_type);

#endif
