/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_to_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:41:38 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 12:51:31 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "libadt.h"
#include "env_manager.h"
#include "libft.h"
#include <stdlib.h>

void	destroy_words(t_word *word);
void	concat_node_ndata(t_word *node, char *data, int len);

static int	determine_string_length(t_word *cur)
{
	int		len;

	len = 0;
	while (cur)
	{
		len += cur->len;
		printf("cur len : %d\n", cur->len);
		if (!(cur->next) || (cur->next->mask & EXPAND_SPLITTED) != 0)
			return (len);
		cur = cur->next;
	}
	return (len);
}

t_word	*fill_string_with_word_data(t_word *cur, char *string)
{
	int		i;

	i = 0;
	if (!cur)
		return (NULL);
	while (cur)
	{
		if (cur->len)
			ft_strlcpy(string + i, cur->data, cur->len + 1);
		printf("filling.... : \n  [%s]\n", string);
		i += cur->len;
		if ((!cur->next) || (cur->next->mask & EXPAND_SPLITTED) != 0)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

char	*word_to_string(t_expansion *set)
{
	char	*string;
	int		len;
	t_word	*start;
	t_word	*end;

	len = determine_string_length(set->first);
	printf("total len : %d\n", len);
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
	return (string);
}

char	**words_to_strings(t_expansion *set, int count)
{
	char	**strings;
	int		i;

	if (!count)
		count = set->count;
	strings = ft_malloc(sizeof(char *) * (count + 1));
	printf("word count: %d\n", count);
	strings[count] = NULL;
	i = -1;
	while (++i < count)
	{
		strings[i] = word_to_string(set);
	}
	return (strings);
}
