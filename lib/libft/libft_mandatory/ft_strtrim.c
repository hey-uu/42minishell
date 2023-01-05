/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:04:32 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/15 22:08:22 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_findidx(char const *s1, char const *s2, int *l, int *len)
{
	int		c1;
	int		c2;
	int		r;

	c1 = 0;
	c2 = 0;
	r = ft_strlen(s1) - 1;
	while (*l <= r)
	{
		if (!c1 && ft_strchr(s2, *(s1 + *l)) != 0)
			(*l)++;
		else
			c1 = 1;
		if (!c2 && ft_strchr(s2, *(s1 + r)) != 0)
			r--;
		else
			c2 = 1;
		if (*l > r)
			*len = 0;
		if (c1 && c2)
			break ;
	}
	*len = r - *l + 1;
}

char	*ft_strtrim(char const *s1, char const *s2)
{
	int		len;
	int		left;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	left = 0;
	if (!*s1)
		len = 0;
	else if (!*s2)
		len = ft_strlen(s1);
	else
		ft_findidx(s1, s2, &left, &len);
	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1 + left, len + 1);
	return (s);
}
