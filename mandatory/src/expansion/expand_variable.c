/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:46:58 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/24 15:19:00 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "expansion_internal.h"
#include "env_manager.h"
#include "libadt.h"
#include "libft.h"

char	*ft_strndup(char *str, int n);

char	*split_variable(char *str, int *idx, int *qmark)
{
	char	*var;
	int		i;

	if (str[0] == '?')
	{
		*qmark = VAR_IS_QMARK;
		(*idx)++;
		return (NULL);
	}
	var = NULL;
	*qmark = VAR_IS_NOT_QMARK;
	i = 0;
	while (is_valid_character_for_variable_name(str[i], i))
		i++;
	if (i > 0)
		var = ft_strndup(str, i);
	(*idx) += i;
	return (var);	
}

int push_quoted_variable_element(char *str, t_words *words)
{
	char	*var;
	char	*val;
	int		i;
	int		qmark;

	i = 1;
	var = split_variable(&str[i], &i, &qmark);
	if (!var && qmark == VAR_IS_NOT_QMARK)
		return (i);
	else if (qmark == VAR_IS_QMARK)
		val = exit_stat_get_str();
	else
		val = env_get(var);
	if (val)
		push_elem_to_cur_word(words, val, ft_strlen(val), WELEM_QUOTED);
	free(var);
	return (i);
}

int	push_unquoted_variable_element(char *str, t_words *words)
{
	char	*var;
	char	*val;
	int		i;
	int		qmark;

// printf("> push_unquoted_variable_element\n");
	i = 1;
	var = split_variable(&str[i], &i, &qmark);
	if (!var && qmark == VAR_IS_NOT_QMARK)
		return (i);
	if (qmark == VAR_IS_QMARK)
		val = exit_stat_get_str();
	else
		val = env_get(var);
	if (val)
		field_split(val, words);
	free(var);
	return (i);
}
