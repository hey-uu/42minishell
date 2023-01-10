/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:47:39 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/10 20:33:18 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	*ft_malloc(size_t size_of)
{
	void	*new;

	new = malloc(size_of);
	if (!new)
	{
		write(2, "failed malloc", 13);
		exit(1);
	}
	return (new);
}
