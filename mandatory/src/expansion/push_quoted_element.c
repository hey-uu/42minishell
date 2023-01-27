/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_quoted_element.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:29:14 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 19:40:25 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "env_manager.h"
#include "exit_stat_manager.h"
#include "expansion_internal.h"

int	push_single_quote_element(char *str, t_words *words)
{
	int	i;

	mask_cur_word(words, EXP_WORD_QUOTED);
	i = 1;
	while (str[i] != '\'')
		i++;
	push_elem_to_cur_word(words, &str[1], i - 1, WELEM_QUOTED);
	return (i + 1);
}

int	push_quoted_variable_element(char *str, t_words *words)
{
	char	*var;
	char	*val;
	int		i;
	int		qmark;

	i = 1;
	var = get_variable_name(&str[i], &i, &qmark);
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

int	push_double_quote_basic_element(char *str, t_words *words)
{
	int		i;

	i = 0;
	while (str[i] != '\"' && str[i] != '$')
		i++;
	push_elem_to_cur_word(words, str, i, WELEM_QUOTED);
	return (i);
}

int	push_double_quote_element(char *str, t_words *words)
{
	int		i;

	mask_cur_word(words, EXP_WORD_QUOTED);
	i = 1;
	while (str[i] != '\"')
	{
		if (str[i] == '$' && str[i + 1] == '\"')
			i += push_dollar_element(&str[i], words);
		else if (str[i] == '$')
			i += push_quoted_variable_element(&str[i], words);
		else
			i += push_double_quote_basic_element(&str[i], words);
	}
	if (get_cur_word(words)->elem_cnt == 0)
		push_elem_to_cur_word(words, &str[1], 0, WELEM_QUOTED);
	return (i + 1);
}
