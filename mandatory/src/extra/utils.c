/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:43:47 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 10:29:38 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(char *str, int n)
{
	char	*new;
	int		i;

	if (!n)
		return (NULL);
	new = ft_malloc(sizeof(char) * (n + 1));
	i = 0;
	while (i < n && str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

void	free_double_char_array(char ***array)
{
	char	**double_array;
	int		i;

	double_array = *array;
	i = -1;
	while (double_array[++i])
	{
		free(double_array[i]);
	}
	free(double_array);
	*array = NULL;
}
