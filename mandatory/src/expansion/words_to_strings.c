/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_to_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:41:38 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 13:05:42 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "expansion_internal.h"
#include "env_manager.h"
#include "libadt.h"
#include "libft.h"

static int	determine_string_length(t_word *cur)
{
	int		len;

// printf("> determine string length...\n");
	len = 0;
	while (cur)
	{
		len += cur->len;
// printf(">>> cur len : %d\n", cur->len);
		if (!(cur->next) || (cur->next->mask & EXPAND_SPLITTED) != 0)
			return (len);
		cur = cur->next;
	}
// printf(">>>>> total len : %d\n", len);
	return (len);
}

t_word	*fill_string_with_word_data(t_word *cur, char *string)
{
	int		i;

// printf("> fill string with word data...\n");
	i = 0;
	if (!cur)
		return (NULL);
	while (cur)
	{
		if (cur->len)
			ft_strlcpy(string + i, cur->data, cur->len + 1);
// printf(">>> filling... : [%s]\n", string);
		i += cur->len;
		if ((!cur->next) || (cur->next->mask & EXPAND_SPLITTED) != 0)
			return (cur);
		cur = cur->next;
	}
// printf(">>>>> total data : [%s]\n", cur->data);
	return (NULL);
}

char	*word_to_string(t_expansion *set)
{
	char	*string;
	int		len;
	t_word	*start;
	t_word	*end;

// printf("> one word to a string...\n");
	len = determine_string_length(set->first);
	string = ft_malloc(sizeof(char) * (len + 1));
	string[len] = 0;
	start = set->first;
	end = fill_string_with_word_data(set->first, string);
	if (end)
	{
		set->first = end->next;
		if (set->last == end)
			set->last = NULL;
		end->next = NULL;
	}
	destroy_words(start);
// printf(">>>>> result string... : [%s]\n", string);
	return (string);
}

char	**words_to_strings(t_expansion *set, int count)
{
	char	**strings;
	int		i;

// printf("> words to strings...\n");
	if (!count)
		count = set->count;
	strings = ft_malloc(sizeof(char *) * (count + 1));
	strings[count] = NULL;
	i = -1;
	while (++i < count)
	{
		strings[i] = word_to_string(set);
	}
// printf(">>>>> strings count: %d\n", count);
	return (strings);
}
