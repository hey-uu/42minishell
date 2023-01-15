/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:02:50 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/15 23:07:41 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "libadt.h"
#include "env_manager.h"
#include "libft.h"
#include <stddef.h>

char	*ft_strndup(char *str, int n);

char	*split_variable(char *word, int *idx)
{
	char	*variable;
	int		i;

	i = 0;
	if (*word == '?')
	{
		i++;
		variable = ft_strdup("?");
	}
	else
	{
		while (word[i] && word[i] != '\'' && word[i] != '\"' && word[i] != '$')
			i++;
		variable = ft_strndup(word, i);
	}
	(*idx) += i;
	return (variable);
}

int	expand_quoted_variable(t_expansion *set, char *word)
{
	t_word	*node;
	char	*variable;
	char	*value;
	int		i;

	node = add_new_word_node_back(set);
	i = 1;
	variable = split_variable(word, &i);
	value = env_get(set->envtab, variable);
	if (value)
	{
		node->len = ft_strlen(value);
		dup_data_to_word(node, value);
	}
	free(variable);
	return (i);
}

int	expand_unquoted_variable(t_expansion *set, char *word)
{
	char	*variable;
	int		i;

	i = 1;
	variable = split_variable(word, &i);
	field_split(set, env_get(set->envtab, variable));
	free(variable);
	return (i);
}
