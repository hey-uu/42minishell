/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darr_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:29:27 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/17 11:52:42 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dynamic_array.h"

int			__darr_double_size__(t_darr *darr);

void	darr_push_int(t_darr *darr, int new_num)
{
	if (darr->used_size == darr->size)
		__darr_double_size__(darr);
	darr->iarr[darr->used_size] = new_num;
	darr->used_size++;
}

void	darr_push_str(t_darr *darr, char *new_str)
{
	if (darr->used_size == darr->size)
		__darr_double_size__(darr);
	darr->strarr[darr->used_size] = new_str;
	darr->used_size++;
}

void	darr_push_intstr(t_darr *darr, int new_num, char *new_str)
{
	if (darr->used_size == darr->size)
		__darr_double_size__(darr);
	darr->iarr[darr->used_size] = new_num;
	darr->strarr[darr->used_size] = new_str;
	darr->istrarr[darr->used_size] = (t_intstr){new_num, new_str};
	darr->used_size++;
}

void	darr_push_strs(t_darr *darr, char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
	{
		darr_push_str(darr, strs[i]);
	}
}
