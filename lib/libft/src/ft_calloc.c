/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:00:12 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/14 18:18:19 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft_internal.h"

void	*ft_calloc(size_t cnt, size_t size)
{
	unsigned char	*new;
	size_t			total;
	size_t			i;

	if (cnt > 0 && size > FT_SIZE_MAX / cnt)
		ft_exit(NULL, BADALLOC);
	total = cnt * size;
	new = ft_malloc(total);
	i = 0;
	while (i < total)
		new[i++] = 0;
	return ((void *) new);
}
