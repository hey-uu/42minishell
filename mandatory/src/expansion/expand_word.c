/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:44:03 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 23:23:23 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "expansion_internal.h"
#include "libadt.h"
#include "env_manager.h"
#include "libft.h"

int	expand_single_quote(t_expansion *set, char *word)
{
	t_word	*node;
	int		i;

// printf("> expand single quote...\n");
	set->quote_exist = QUOTED_CHAR_EXIST;
	node = add_new_word_node_back(set);
	node->mask |= EXPAND_QUOTED;
	i = 1;
	while (word[i] && word[i] != '\'')
		i++;
	node->len = i - 1;
	dup_data_to_word(node, &word[1]);
	return (i + 1);
}

int	expand_double_quote_basic(t_expansion *set, char *word)
{
	t_word	*node;
	int		i;

// printf("> expand double quote basic...\n");
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

	set->quote_exist = QUOTED_CHAR_EXIST;
// printf("> expand double quote...\n");
	node = add_new_word_node_back(set);
	node->mask |= EXPAND_QUOTED;
	i = 1;
	while (word[i] && word[i] != '\"')
	{
		if (word[i] == '$' && word[i + 1] == '\"')
		{
			concat_node_ndata(node, "$", 1);
			i += 1;
		}
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

// printf("expand basic...\n");
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

int	append_dollar_node(t_expansion *set)
{
	t_word	*node;

	node = add_new_word_node_back(set);
	node->len = 1;
	dup_data_to_word(node, "$");
	return (1);
}

t_expansion	*expand_word(char *word)
{
	t_expansion	*set;
	int			i;

// printf("> expand word! so funny!! *^^*\n");
	set = create_expansion_set();
	i = 0;
	while (word[i])
	{
		if (word[i] == '\'')
			i += expand_single_quote(set, &word[i]);
		else if (word[i] == '\"')
			i += expand_double_quote(set, &word[i]);
		else if (word[i] == '$' && word[i + 1] == '\0')
			i += append_dollar_node(set);
		else if (word[i] == '$')
			i += expand_unquoted_variable(set, &word[i]);
		else
			i += expand_basic(set, &word[i]);
// printf("====> current pos: %s\n", word + i);
	}
	return (set);
}
