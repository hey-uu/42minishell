/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:49:25 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/12 21:38:16 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

/**
 * @brief Lexer
 * 
 */

/*-------------- USER DEFINED HEADERS ------------*/

# include "minishell.h"
# include "error.h"

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
