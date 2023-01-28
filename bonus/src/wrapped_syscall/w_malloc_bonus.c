/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_malloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:32:37 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/26 23:35:29 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*w_malloc(size_t size_of)
{
	void	*new;

	new = malloc(size_of);
	if (!new)
	{
		perror("goldsh : malloc");
		exit(2);
	}
	return (new);
}
