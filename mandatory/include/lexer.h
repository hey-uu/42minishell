/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 21:49:25 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/20 02:06:06 by yeonhkim         ###   ########.fr       */
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

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum e_lexer_result_status
{
	LEXER_FAILURE = -1,
	LEXER_SUCCESS = 0
};

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
