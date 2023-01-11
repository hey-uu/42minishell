/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:04:27 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/10 20:46:03 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	const char	new_c = (char) c;
	size_t		i;
	char		*pos;

	i = 0;
	pos = NULL;
	while (s[i])
	{
		if (s[i] == new_c)
			pos = (char *)(s + i);
		i++;
	}
	if (!new_c)
		return ((char *)(s + i));
	return (pos);
}
