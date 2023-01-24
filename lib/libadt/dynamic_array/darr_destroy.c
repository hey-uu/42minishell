/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darr_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:58:19 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/24 07:39:57 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_dynamic_array.h"

void	darr_flush_strarr(char ***strarr, int used_size)
{
	int	i;

	i = 0;
	while (i < used_size)
	{
		free((*strarr)[i]);
		i++;
	}
	free(*strarr);
	*strarr = NULL;
}

void	darr_flush_iarr(int **iarr)

{
	free(*iarr);
	*iarr = NULL;
}

void	darr_flush_istrarr(t_intstr **istrarr)
{
	free(*istrarr);
	*istrarr = NULL;
}

void	darr_flush(t_darr *darr)
{
	if (darr->type == DARR_STR || darr->type == DARR_INTSTR)
		darr_flush_strarr(&darr->strarr, darr->used_size);
	if (darr->type == DARR_INT || darr->type == DARR_INTSTR)
		darr_flush_iarr(&darr->iarr);
	if (darr->type == DARR_INTSTR)
		darr_flush_istrarr(&darr->istrarr);
	darr->used_size = 0;
}

void	destroy_darr(t_darr **darr)
{
	darr_flush(*darr);
	free(*darr);
	*darr = NULL;
}
