/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darr_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 01:28:41 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 00:42:00 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "t_dynamic_array.h"

int	darr_pop_int(t_darr *darr)
{
	int	popped;
	int	i;

	popped = darr->iarr[0];
	i = 0;
	while (i < darr->used_size - 1)
	{
		darr->iarr[i] = darr->iarr[i + 1];
		i++;
	}
	darr->used_size--;
	return (popped);
}

char	*darr_pop_str(t_darr *darr)
{
	char	*popped;
	int		i;

	popped = darr->strarr[0];
	i = 0;
	while (i < darr->used_size - 1)
	{
		darr->strarr[i] = darr->strarr[i + 1];
		i++;
	}
	darr->used_size--;
	return (popped);
}

t_intstr	darr_pop_intstr(t_darr *darr)
{
	t_intstr	popped;
	int			i;

	popped = (t_intstr){darr->iarr[0], darr->strarr[0]};
	i = 0;
	while (i < darr->used_size - 1)
	{
		darr->iarr[i] = darr->iarr[i + 1];
		darr->strarr[i] = darr->strarr[i + 1];
		darr->istrarr[i] = darr->istrarr[i + 1];
		i++;
	}
	darr->used_size--;
	return (popped);
}
