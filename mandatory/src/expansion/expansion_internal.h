/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:22:15 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/24 20:12:37 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_INTERNAL_H
# define EXPANSION_INTERNAL_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "s_expansion.h"
# include "libadt.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

# define INITIAL_DARR_SIZE 10
# define INITIAL_WORD_ARR_SIZE 3
# define INITIAL_WORDELEM_ARR_SIZE 10

# define AMBIGUOUS_REDIRECT -1
# define IS_WILDCARD -1

enum e_word_elem_type
{
	WELEM_NONE,
	WELEM_QUOTED,
	WELEM_WILDCARD
};

enum e_word_mask
{
	EXP_WORD_NONE,
	EXP_WORD_WILDCARD = (1 << 0),
	EXP_WORD_QUOTED = (1 << 1)
};

typedef char	t_bool;

/*------------- STRUCT DECLARATIONS --------------*/

// word_array_utils.c
void	init_word_element_array(t_word *word, int initial_size);
void	init_word_array(t_words *words, int initial_size);
void	free_word_array(t_words *words);
void	__grow_word_array__(t_words *words);
void	__grow_word_element_array__(t_word *word);
t_word	*get_cur_word(t_words *words);
t_word	*get_new_word(t_words *words);
void	push_elem_to_word(t_word *word, char *str, int len, int type);
void	push_elem_to_cur_word(t_words *words, char *str, int len, int type);
void	push_elem_to_new_word(t_words *words, char *str, int len, int type);
void	mask_cur_word(t_words *words, int mask);

// append_word_to_strings.c
void	push_words_to_strings(t_words *words, t_darr *strings);
void	push_word_to_strings(t_word *word, t_darr *strings);
int		push_wildcard_element(char *str, t_words *words);

// expand_word.c
void	expand_word_to_strings(char *word, t_darr *strings);

// expand_wildcard.c
void	push_wildcard_expansion_to_strings(t_word *word, t_darr *strings);

// field_split.c
void	field_split(char *val, t_words *words);

// expand_variable.c
char	*split_variable(char *str, int *idx, int *qmark);
int 	push_quoted_variable_element(char *str, t_words *words);
int		push_unquoted_variable_element(char *str, t_words *words);

int		is_valid_character_for_variable_name(char c, int i);

#endif
