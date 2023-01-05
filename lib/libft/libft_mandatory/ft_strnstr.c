/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:04:18 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/15 22:08:22 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haydequeue, const char *needle, size_t len)
{
	size_t			i;
	const size_t	nd_len = ft_strlen(needle);

	if (needle == 0 || (!haydequeue[0] && !needle[0]))
		return ((char *) haydequeue);
	i = 0;
	while (haydequeue[i] && i + nd_len <= len)
	{
		if (ft_strncmp(haydequeue + i, needle, nd_len) == 0)
			return ((char *)(haydequeue + i));
		i++;
	}
	return (NULL);
}
