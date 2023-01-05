/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:00:12 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/26 15:51:55 by hyeyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
