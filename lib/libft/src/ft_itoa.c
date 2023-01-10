/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:01:04 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/10 20:32:39 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_internal.h"

static size_t	ft_getlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	const size_t	len = ft_getlen(n);
	size_t			i;
	char			*res;

	res = malloc(len + 1);
	if (!res)
		return (NULL);
	if (n == 0)
		res[0] = '0';
	else if (n < 0)
		res[0] = '-';
	i = len;
	while (n != 0)
	{
		res[--i] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	res[len] = '\0';
	return (res);
}
