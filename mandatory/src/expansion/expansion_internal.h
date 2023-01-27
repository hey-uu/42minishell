/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:22:15 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 18:15:14 by yeonhkim         ###   ########.fr       */
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

// expand_word.c
void	expand_word_to_strings(char *word, t_darr *strings);
// push_quoted_element.c
int		push_single_quote_element(char *str, t_words *words);
int		push_double_quote_element(char *str, t_words *words);
int		push_dollar_element(char *str, t_words *words);
int		push_unquoted_variable_element(char *str, t_words *words);
int		push_wildcard_element(char *str, t_words *words);
int		push_basic_element(char *str, t_words *words);
// push_words_to_strings.c
void	push_words_to_strings(t_words *words, t_darr *strings);

// get_variable_name.c
char	*get_variable_name(char *str, int *idx, int *qmark);
// field_split.c
void	field_split(char *val, t_words *words);

// get_next_file_name.c
char	*get_next_file_name(void);
// get_pattern_features.c
int		get_pattern_char(t_word *word, int i);
int		get_pattern_len(t_word *word);
// match_wildcard_pattern.c
int		is_matched(t_word *word, char *string);

// words_allocation.c
void	init_word_element_array(t_word *word, int initial_size);
void	init_words(t_words *words, int initial_size);
void	free_words(t_words *words);
void	grow_word_array(t_words *words);
void	grow_word_element_array(t_word *word);
// words_get.c
t_word	*get_cur_word(t_words *words);
t_word	*get_new_word(t_words *words);

// words_mask.c
void	mask_cur_word(t_words *words, int mask);
// words_push.c
void	push_elem_to_cur_word(t_words *words, char *str, int len, int type);

// extra
char	*ft_strndup(char *str, int n);

#endif
