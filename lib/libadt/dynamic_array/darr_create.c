/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darr_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:16:39 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/24 07:32:25 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_dynamic_array.h"
#include "libft.h"

void	init_dynamic_array(t_darr *darr, int initial_size, int type)
{
	darr->type = type;
	darr->size = initial_size;
	darr->used_size = 0;
	darr->iarr = NULL;
	darr->strarr = NULL;
	darr->istrarr = NULL;
	if (type == DARR_INT || type == DARR_INTSTR)
		darr->iarr = ft_malloc(darr->size * sizeof(int));
	if (type == DARR_STR || type == DARR_INTSTR)
		darr->strarr = ft_calloc(darr->size, sizeof(char *));
	if (type == DARR_INTSTR)
		darr->istrarr = ft_calloc(darr->size, sizeof(t_intstr));
}

t_darr	*create_dynamic_array(int initial_size, int type)
{
	t_darr	*darr;

	darr = ft_malloc(sizeof(t_darr));
	init_dynamic_array(darr, initial_size, type);
	return (darr);
}
