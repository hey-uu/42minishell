/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:04:37 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/10 20:47:09 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_internal.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sublen;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (len == 0 || start >= slen)
		sublen = 0;
	else if (len < (slen - start))
		sublen = len;
	else
		sublen = slen - start;
	sub = (char *)malloc(sublen + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, sublen + 1);
	return (sub);
}
