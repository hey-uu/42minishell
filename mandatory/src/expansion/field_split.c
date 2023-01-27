/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:33:03 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 09:03:01 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion_internal.h"

static int	is_field_separator(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int	pass_field_separators(char *value)
{
	int	i;

	i = 1;
	while (is_field_separator(value[i]))
		i++;
	return (i);
}

static int	push_non_field_separator_element(char *str, t_words *words)
{
	int	i;

	i = 0;
	while (str[i] && !is_field_separator(str[i]))
		i++;
	push_elem_to_cur_word(words, str, i, WELEM_NONE);
	return (i);
}

static int	push_splitted_element(char *str, t_words *words)
{
	int	i;

	i = 0;
	while (str[i] && !is_field_separator(str[i]))
	{
		if (str[i] == '*')
			i += push_wildcard_element(&str[i], words);
		else
			i += push_non_field_separator_element(&str[i], words);
	}
	return (i);
}

void	field_split(char *val, t_words *words)
{
	int	i;

	i = 0;
	while (val[i])
	{
		if (is_field_separator(val[i]))
		{
			i += pass_field_separators(&val[i]);
			get_new_word(words);
		}
		if (val[i])
		{
			i += push_splitted_element(&val[i], words);
		}
	}
}
