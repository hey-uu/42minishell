/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:50:44 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/24 22:50:47 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include "expansion_internal.h"

int	is_valid_variable_name_character(char c, int i)
{
	if (i == 0 && !(ft_isalpha(c) || c == '_'))
		return (0);
	if (!(ft_isalnum(c) || c == '_'))
		return (0);
	return (1);
}

char	*get_variable_name(char *str, int *idx, int *qmark)
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
	while (is_valid_variable_name_character(str[i], i))
		i++;
	if (i > 0)
		var = ft_strndup(str, i);
	(*idx) += i;
	return (var);
}
