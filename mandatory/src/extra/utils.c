/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:43:47 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 06:51:39 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>
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
