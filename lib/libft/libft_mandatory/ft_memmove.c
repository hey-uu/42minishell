/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:02:46 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/27 14:02:47 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *str, size_t len)
{
	size_t					i;
	unsigned char			*dst2;
	const unsigned char		*str2 = (const unsigned char *) str;

	dst2 = (unsigned char *)dst;
	if (dst > str)
	{
		i = len;
		while (i--)
			dst2[i] = str2[i];
	}
	else if (dst < str)
	{
		i = 0;
		while (i < len)
		{
			dst2[i] = str2[i];
			i++;
		}
	}
	return (dst);
}
