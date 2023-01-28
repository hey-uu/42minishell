/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:20:28 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:17:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion_internal_bonus.h"

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
	}
}

void	expand_word_to_strings(char *word, t_darr *strings)
{
	t_words	words;

	init_words(&words, INITIAL_WORD_ARR_SIZE);
	expand_word_to_words(word, &words);
	push_words_to_strings(&words, strings);
	free_words(&words);
}
