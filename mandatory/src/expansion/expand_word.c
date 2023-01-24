/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:20:28 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/24 17:27:15 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "expansion_internal.h"
#include "libft.h"
#include "libadt.h"
#include "s_tree_node.h"

int	push_single_quote_element(char *str, t_words *words)
{
	int			i;
	
	mask_cur_word(words, EXP_WORD_QUOTED);
	i = 1;
	while (str[i] != '\'')
		i++;
	push_elem_to_cur_word(words, &str[1], i - 1, WELEM_NONE);
	return (i + 1);
}

int	push_dollar_element(char *str, t_words *words)
{
	push_elem_to_cur_word(words, str, 1, WELEM_NONE);
	return (1);
}

int	push_double_quote_basic_element(char *str, t_words *words)
{
	int		i;

	i = 0;
	while (str[i] != '\"' && str[i] != '$')
		i++;
	push_elem_to_cur_word(words, str, i, WELEM_QUOTED);
	return (i);
}

int	push_double_quote_element(char *str, t_words *words)
{
	int		i;

	mask_cur_word(words, EXP_WORD_QUOTED);
	i = 1;
	while (str[i] != '\"')
	{
		if (str[i] == '$' && str[i + 1] == '\"')
			i += push_dollar_element(&str[i], words);
		else if (str[i] == '$')
			i += push_quoted_variable_element(&str[i], words);
		else
			i += push_double_quote_basic_element(&str[i], words);
	}
	return (i + 1);
}

int	push_wildcard_element(char *str, t_words *words)
{
	int	i;

// printf("> push_wildcard_element\n");
	i = 0;
	while (str[i] == '*')
		i++;
	mask_cur_word(words, EXP_WORD_WILDCARD);
// printf(">> wordcount: %d\n", words->word_cnt);
// printf(">> mask: %d\n", get_cur_word(words)->mask);
	push_elem_to_cur_word(words, &str[0], i, WELEM_WILDCARD);
// printf(">> mask: %d\n", get_cur_word(words)->mask);
	return (i);
}

int	push_basic_element(char *str, t_words *words)
{
	int	i;
	i = 0;
	while (str[i] && \
		str[i] != '\'' && str[i] != '\"' && str[i] != '$' && str[i] != '*')
		i++;
	push_elem_to_cur_word(words, str, i, WELEM_NONE);
	return (i);
}

void	expand_word_to_words(char *word, t_words *words)
{
	int	i;

	i = 0;
	while (word[i])
	{
		if (word[i] == '\'')
			i += push_single_quote_element(&word[i], words);
		else if (word[i] == '\"')
			i += push_double_quote_element(&word[i], words);
		else if (word[i] == '$' && word[i + 1] == '\0')
			i += push_dollar_element(&word[i], words);
		else if (word[i] == '$')
			i += push_unquoted_variable_element(&word[i], words);
		else if (word[i] == '*')
			i += push_wildcard_element(&word[i], words);
		else
			i += push_basic_element(&word[i], words);
// printf("====> current pos: %s\n", word + i);
	}
}

void	expand_word_to_strings(char *word, t_darr *strings)
{
	t_words	words;

	init_word_array(&words, INITIAL_WORD_ARR_SIZE);
	expand_word_to_words(word, &words);
	push_words_to_strings(&words, strings);
	free_word_array(&words);
}