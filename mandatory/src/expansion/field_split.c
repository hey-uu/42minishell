/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:08:13 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 01:15:24 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"

void	dup_data_to_word(t_word *node, char *word);
t_word	*add_new_word_node_back(t_expansion *set);


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

static int	pass_non_field_separators(t_word *node, char *value)
{
	int	i;

	i = 1;
	while (value[i] && !is_field_separator(value[i]))
	{
		if (value[i] == '*')
			node->mask |= EXPAND_WILDCARD;
		i++;
	}
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
		{
			i += pass_field_separators(&value[i]);
			flag = 1;
		}
		if (value[i] && !is_field_separator(value[i]))
		{
			node = add_new_word_node_back(set);
			if (flag)
				node->mask |= EXPAND_SPLITTED;
			node->len = pass_non_field_separators(node, &value[i]);
			dup_data_to_word(node, &value[i]);
			i += node->len;
			flag = 0;
		}
	}
	if (flag)
	{
		add_new_word_node_back(set);
		node->mask |= EXPAND_SPLITTED;
	}
}
