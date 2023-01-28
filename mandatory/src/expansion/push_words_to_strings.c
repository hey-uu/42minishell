/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_words_to_strings.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:02:02 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 19:08:55 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include "expansion_internal.h"

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
		str[len] = '\0';
		copy_word_to_string(word->elem_arr, word->elem_cnt, str);
		darr_push_str(strings, str);
	}
}

void	expand_wildcard_to_strings(t_word *word, t_darr *strings)
{
	char	*file_name;
	int		count;

	count = 0;
	while (1)
	{
		file_name = get_next_file_name((get_pattern_char(word, 0) == '.'));
		if (!file_name)
			break ;
		if (is_matched(word, file_name))
		{
			darr_push_str(strings, ft_strdup(file_name));
			count++;
		}
	}
	if (!count)
		push_word_to_strings(word, strings);
}

void	push_words_to_strings(t_words *words, t_darr *strings)
{
	int	i;

	i = 0;
	while (i < words->word_cnt)
	{
		if ((words->word_arr[i].mask & EXP_WORD_WILDCARD))
			expand_wildcard_to_strings(&words->word_arr[i], strings);
		else if (words->word_arr[i].elem_cnt > 0)
			push_word_to_strings(&words->word_arr[i], strings);
		i++;
	}
}
