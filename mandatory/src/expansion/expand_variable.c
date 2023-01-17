/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:02:50 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/17 14:55:36 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "expansion_internal.h"
#include "env_manager.h"
#include "libadt.h"
#include "libft.h"

static char	*split_variable(char *word, int *idx, int *question_mark)
{
	char	*variable;
	int		i;

printf("> split variable...\n");
	variable = NULL;
	i = 0;
	if (word[0] == '?')
	{
printf(">>> this is question mark...\n");
		*question_mark = IS_QMARK;
		i++;
	}
	else
	{
		while (word[i] && word[i] != '\'' && word[i] != '\"' \
				&& word[i] != '$' && word[i] != '*' && word[i] != '?')
			i++;
		if (i)
			variable = ft_strndup(word, i);
printf(">>> the variable is : [%s]...\n", variable);
		*question_mark = IS_NOT_QMARK;
	}
	(*idx) += i;
	return (variable);
}

void	concat_node_ndata(t_word *node, char *data, int len)
{
	char	*old_data;
	int		old_len;

printf("> concat node ndata...\n");
	old_data = node->data;
	old_len = node->len;
	if (!data || !len)
		return ;
	if (!old_data)
	{
		node->len = len;
		dup_data_to_word(node, data);
	}
	else
	{
		node->data = ft_malloc(sizeof(char) * (old_len + len + 1));
		ft_strlcpy(node->data + old_len, data, len + 1);
		node->len = old_len + len;
		free(old_data);
	}
printf(">>> current node data: [%s]\n", node->data);
}

int	expand_quoted_variable(t_expansion *set, char *word)
{
	char	*variable;
	char	*value;
	int		question_mark;
	int		i;

printf("> expand quoted variable...\n");
	i = 1;
	variable = split_variable(&word[i], &i, &question_mark);
	if (!variable && question_mark == IS_NOT_QMARK)
		return (i);
printf(">>> expand quoted variable: [%s]...\n", variable);
	if (question_mark == IS_QMARK)
		value = exit_stat_get_str();
	else
		value = env_get(variable);
printf(">>> found variable's value: [%s]...\n\n", value);
	if (value)
		concat_node_ndata(set->last, value, ft_strlen(value));
	if (question_mark == IS_QMARK)
		free(value);
	free(variable);
	return (i);
}

int	expand_unquoted_variable(t_expansion *set, char *word)
{
	char	*variable;
	char	*value;
	int		question_mark;
	int		i;

printf("> expand unquoted variable\n");
	i = 1;
	variable = split_variable(&word[i], &i, &question_mark);
	if (!variable && question_mark == IS_NOT_QMARK)
		return (i);
printf(">>> expand unquoted variable: [%s]...\n\n", variable);
	if (question_mark == IS_QMARK)
		value = exit_stat_get_str();
	else
		value = env_get(variable);
printf(">>> found variable's value: [%s]...\n\n", value);
	field_split(set, value);
	if (question_mark == IS_QMARK)
		free(value);
	free(variable);
	return (i);
}
