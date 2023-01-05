/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:02:51 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/27 14:02:52 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				i;
	unsigned char		*ptr;
	const unsigned char	new_c = (unsigned char) c;

	ptr = (unsigned char *) b;
	i = 0;
	while (i < len)
		ptr[i++] = new_c;
	return (b);
}
