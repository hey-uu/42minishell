/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_word_to_strings.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:02:02 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/24 17:15:57 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "expansion_internal.h"
#include "libft.h"
#include "libadt.h"

static int	get_string_length_of_word(t_word *word)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (i < word->elem_cnt)
	{
		len += word->elem_arr[i].len;
		i++;
	}
	return (len);
}

void	copy_word_to_string(t_word_elem *elem_arr, int elem_cnt, char *str)
{
	int		offset;
	int		i;

	offset = 0;
	i = 0;
	while (i < elem_cnt)
	{
		if (elem_arr[i].len > 0)
			ft_strlcpy(str + offset, elem_arr[i].data, elem_arr[i].len + 1);
		offset += elem_arr[i].len;
		i++;
	}
}

void	push_word_to_strings(t_word *word, t_darr *strings)
{
	int		len;
	char	*str;
	
	len = get_string_length_of_word(word);
	if (!len && ((word->mask & EXP_WORD_QUOTED) == 0))
		darr_push_str(strings, NULL);
	else
	{
		str = ft_malloc(sizeof(char) * (len + 1));
		copy_word_to_string(word->elem_arr, word->elem_cnt, str);
		darr_push_str(strings, str);
	}
}

void	push_words_to_strings(t_words *words, t_darr *strings)
{
	int	i;

	i = 0;
	while (i < words->word_cnt)
	{
// printf("masks: %d: %d\n", i, words->word_arr[i].mask);
		if ((words->word_arr[i].mask & EXP_WORD_WILDCARD))
			push_wildcard_expansion_to_strings(&words->word_arr[i], strings);
		else
			push_word_to_strings(&words->word_arr[i], strings);
		i++;
	}
}
