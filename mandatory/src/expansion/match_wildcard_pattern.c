/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match_wildcard_pattern.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:07:27 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 19:40:04 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "expansion_internal.h"

void	init_lookup_table(t_bool ***table, int pattern_len, int string_len)
{
	int	i;

	*table = ft_calloc(string_len + 1, sizeof(t_bool *));
	i = 0;
	while (i < string_len + 1)
	{
		(*table)[i] = ft_calloc(pattern_len + 1, sizeof(t_bool));
		i++;
	}
}

void	destroy_lookup_table(t_bool ***table, int string_len)
{
	int	i;

	i = 0;
	while (i < string_len + 1)
	{
		free((*table)[i]);
		i++;
	}
	free(*table);
	*table = NULL;
}

void	fill_initial_conditions(t_bool **lookup, t_word *word, int pattern_len)
{
	int	j;

	lookup[0][0] = 1;
	j = 1;
	while (j <= pattern_len)
	{
		if (get_pattern_char(word, j - 1) == IS_WILDCARD)
			lookup[0][j] = lookup[0][j - 1];
		j++;
	}
}

void	fill_lookup_table(t_bool **lookup, t_word *word, char *str, int len[2])
{
	int	i;
	int	j;
	int	c;

	fill_initial_conditions(lookup, word, len[0]);
	i = 1;
	while (i <= len[1])
	{
		j = 1;
		while (j <= len[0])
		{
			c = get_pattern_char(word, j - 1);
			if (c == IS_WILDCARD)
				lookup[i][j] = (lookup[i][j - 1] || lookup[i - 1][j]);
			else if (c == (unsigned char)str[i - 1])
				lookup[i][j] = lookup[i - 1][j - 1];
			else
				lookup[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	is_matched(t_word *word, char *string)
{
	const int	pattern_len = get_pattern_len(word);
	const int	string_len = ft_strlen(string);
	t_bool		**lookup;
	t_bool		res;

	init_lookup_table(&lookup, pattern_len, string_len);
	fill_lookup_table(lookup, word, string, (int [2]){pattern_len, string_len});
	res = lookup[string_len][pattern_len];
	destroy_lookup_table(&lookup, string_len);
	return (res);
}
