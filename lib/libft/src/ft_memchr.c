/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:02:11 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/10 20:40:55 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*s2;
	const unsigned char	new_c = (unsigned char) c;

	s2 = (unsigned char *) s;
	i = 0;
	while ((i < n) && (s2[i] != new_c))
		i++;
	if (i == n)
		return (NULL);
	return ((void *) s2 + i);
}
