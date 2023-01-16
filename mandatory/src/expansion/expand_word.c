/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:44:03 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 23:22:09 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "expansion_internal.h"
#include "libadt.h"
#include "env_manager.h"
#include "libft.h"

int	expand_single_quote(t_expansion *set, char *word)
{
	t_word	*node;
	int		i;

	node = add_new_word_node_back(set);
	node->mask |= EXPAND_QUOTED;
	i = 1;
	while (word[i] && word[i] != '\'')
		i++;
	node->len = i;
	dup_data_to_word(node, &word[1]);
	return (i + 1);
}

int	expand_double_quote_basic(t_expansion *set, char *word)
{
	t_word	*node;
	int		i;

	node = set->last;
	i = 0;
	while (word[i] && word[i] != '\"' && word[i] != '$')
		i++;
	concat_node_ndata(node, word, i);
	return (i);
}

int	expand_double_quote(t_expansion *set, char *word)
{
	t_word	*node;
	int		i;

	node = add_new_word_node_back(set);
	node->mask |= EXPAND_QUOTED;
	i = 1;
	while (word[i] && word[i] != '\"')
	{
		if (word[i] == '$')
			i += expand_quoted_variable(set, &word[i]);
		else
			i += expand_double_quote_basic(set, &word[i]);
	}
	return (i + 1);
}

int	expand_basic(t_expansion *set, char *word)
{
	t_word	*node;
	int		i;

	node = add_new_word_node_back(set);
	i = 0;
	while (word[i] && word[i] != '\'' && word[i] != '\"' && word[i] != '$')
	{
		if (word[i] == '*')
			node->mask |= EXPAND_WILDCARD;
		i++;
	}
	node->len = i;
	dup_data_to_word(node, word);
	return (i);
}

t_expansion	*expand_word(char *word)
{
	t_expansion	*set;
	int			i;

	set = create_expansion_set(word);
	i = 0;
	while (word[i])
	{
		if (word[i] == '\'')
			i += expand_single_quote(set, &word[i]);
		else if (word[i] == '\"')
			i += expand_double_quote(set, &word[i]);
		else if (word[i] == '$')
			i += expand_unquoted_variable(set, &word[i]);
		else
			i += expand_basic(set, &word[i]);
	}
	return (set);
}
