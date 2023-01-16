/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:02:50 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 12:18:18 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "libadt.h"
#include "env_manager.h"
#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(char *str, int n);
t_word	*add_new_word_node_back(t_expansion *set);
void	dup_data_to_word(t_word *node, char *word);
void	field_split(t_expansion *set, char *value);

static char	*split_variable(char *word, int *idx)
{
	char	*variable;
	int		i;

	variable = NULL;
	i = 0;
	if (*word == '?')
	{
		i++;
		variable = ft_strdup("?");
	}
	else
	{
		while (word[i] && word[i] != '\'' && word[i] != '\"' \
				&& word[i] != '$' && word[i] != '*' && word[i] != '?')
			i++;
		if (i)
			variable = ft_strndup(word, i);
	}
	(*idx) += i;
	return (variable);
}

void	concat_node_ndata(t_word *node, char *data, int len)
{
	char	*old_data;
	int		old_len;

	old_data = node->data;
	old_len = node->len;
	if (!data)
		return ;
	if (!old_data)
		dup_data_to_word(node, data);
	else
	{
		node->data = ft_malloc(sizeof(char) * (old_len + len + 1));
		ft_strlcpy(node->data, old_data, old_len + 1);
		ft_strlcpy(node->data + old_len, data, len + 1);
		node->len = old_len + len;
		free(old_data);
	}
}

int	expand_quoted_variable(t_expansion *set, char *word)
{
	char	*variable;
	char	*value;
	int		i;

	i = 1;
	variable = split_variable(&word[i], &i);
	printf("expand quoted variable: [%s]...\n", variable);
	value = env_get(set->envtab, variable);
	if (value)
	{
		concat_node_ndata(set->last, value, ft_strlen(value));
	}
	free(variable);
	return (i);
}

int	expand_unquoted_variable(t_expansion *set, char *word)
{
	char	*variable;
	char	*value;
	int		i;

	i = 1;
	variable = split_variable(&word[i], &i);
	printf("expand unquoted variable: [%s]...\n\n", variable);
	value = env_get(set->envtab, variable);
	printf("found variable's value: [%s]...\n\n", value);
	field_split(set, value);
	free(variable);
	return (i);
}
