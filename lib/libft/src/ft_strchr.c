/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:03:30 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/10 20:43:14 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	const char	new_c = (char) c;
	size_t		i;

	i = 0;
	while (s[i] && s[i] != new_c)
		i++;
	if (s[i] != new_c)
		return (NULL);
	return ((char *)s + i);
}
