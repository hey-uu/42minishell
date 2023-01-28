/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_unquoted_element_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:28:10 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:17:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env_manager_bonus.h"
#include "exit_stat_manager_bonus.h"
#include "expansion_internal_bonus.h"

int	push_dollar_element(char *str, t_words *words)
{
	push_elem_to_cur_word(words, str, 1, WELEM_NONE);
	return (1);
}

int	push_unquoted_variable_element(char *str, t_words *words)
{
	char	*var;
	char	*val;
	int		i;
	int		qmark;

	i = 1;
	var = get_variable_name(&str[i], &i, &qmark);
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

int	push_wildcard_element(char *str, t_words *words)
{
	int	i;

	i = 0;
	while (str[i] == '*')
		i++;
	mask_cur_word(words, EXP_WORD_WILDCARD);
	push_elem_to_cur_word(words, &str[0], i, WELEM_WILDCARD);
	return (i);
}

int	push_basic_element(char *str, t_words *words)
{
	int	i;

	i = 0;
	while (str[i] && \
		str[i] != '\'' && str[i] != '\"' && str[i] != '$' && str[i] != '*')
		i++;
	push_elem_to_cur_word(words, str, i, WELEM_NONE);
	return (i);
}
