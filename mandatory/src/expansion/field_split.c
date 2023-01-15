/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:08:13 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/15 23:15:04 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

static int	is_field_separator(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int	pass_field_separators(char *value)
{
	int	i;

	i = 1;
	while (value[i] && is_field_separator(value[i]))
		i++;
	return (i);
}

static int	pass_non_field_separators(char *value)
{
	int	i;

	i = 1;
	while (value[i] && !is_field_separator(value[i]))
		i++;
	return (i);
}

void	field_split(t_expansion *set, char *value)
{
	t_word	*node;
	int		flag;
	int		i;

	if (!value)
		return ;
	i = 0;
	flag = 0;
	while (value[i])
	{
		if (is_field_separator(value[i]))
			i += pass_field_separators(&value[i]);
		if (value[i] && !is_field_separator(value[i]))
		{
			node = add_new_word_node_back(set);
			if (flag)
				node->quote = EXP_SPLITTED;
			node->len = pass_non_field_separators(&value[i]);
			dup_data_to_word(node, &value[i]);
			i += node->len;
			flag = 1;
		}
	}
}
