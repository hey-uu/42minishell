/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:22:15 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 19:10:16 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_INTERNAL_H
# define EXPANSION_INTERNAL_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "libadt.h"
# include "str_utils.h"
# include "s_expansion.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

# define INITIAL_DARR_SIZE			10
# define INITIAL_WORD_ARR_SIZE		3
# define INITIAL_WORDELEM_ARR_SIZE	10

# define IS_WILDCARD				-1

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

/*------------------ TYPE DEFINE -----------------*/

typedef int	t_bool;

/*------------- STRUCT DECLARATIONS --------------*/

/* expand word */
void	expand_word_to_strings(char *word, t_darr *strings);

/* push quoted element */
int		push_single_quote_element(char *str, t_words *words);
int		push_double_quote_element(char *str, t_words *words);
int		push_dollar_element(char *str, t_words *words);
int		push_unquoted_variable_element(char *str, t_words *words);
int		push_wildcard_element(char *str, t_words *words);
int		push_basic_element(char *str, t_words *words);

void	push_words_to_strings(t_words *words, t_darr *strings);

char	*get_variable_name(char *str, int *idx, int *qmark);
void	field_split(char *val, t_words *words);

char	*get_next_file_name(int is_dot);

int		get_pattern_char(t_word *word, int i);
int		get_pattern_len(t_word *word);

t_word	*get_cur_word(t_words *words);
t_word	*get_new_word(t_words *words);

int		is_matched(t_word *word, char *string);

void	init_word_element_array(t_word *word, int initial_size);
void	init_words(t_words *words, int initial_size);
void	free_words(t_words *words);

void	grow_word_array(t_words *words);
void	grow_word_element_array(t_word *word);

void	mask_cur_word(t_words *words, int mask);
void	push_elem_to_cur_word(t_words *words, char *str, int len, int type);

#endif
