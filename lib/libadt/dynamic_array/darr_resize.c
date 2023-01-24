/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darr_resize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:19:04 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 00:42:07 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_dynamic_array.h"
#include "libft.h"

void	__darr_double_size_int_arr__(t_darr *darr)
{
	int	*new;

	new = ft_malloc(sizeof(int) * darr->size * 2);
	ft_memcpy(new, darr->iarr, sizeof(int) * darr->used_size);
	free(darr->iarr);
	darr->iarr = new;
}

void	__darr_double_size_str_arr__(t_darr *darr)
{
	char	**new;

	new = ft_calloc(darr->size * 2, sizeof(char *));
	ft_memcpy(new, darr->strarr, sizeof(char *) * darr->used_size);
	free(darr->strarr);
	darr->strarr = new;
}

void	__darr_double_size_intstr_arr__(t_darr *darr)
{
	int			*new_iarr;
	char		**new_strarr;
	t_intstr	*new_istrarr;

	new_iarr = ft_calloc(darr->size * 2, sizeof(int));
	new_strarr = ft_calloc(darr->size * 2, sizeof(char *));
	new_istrarr = ft_calloc(darr->size * 2, sizeof(t_intstr));
	ft_memcpy(new_iarr, darr->iarr, sizeof(int) * darr->used_size);
	ft_memcpy(new_strarr, darr->strarr, sizeof(char *) * darr->used_size);
	ft_memcpy(new_istrarr, darr->istrarr, sizeof(t_intstr) * darr->used_size);
	free(darr->iarr);
	free(darr->strarr);
	free(darr->istrarr);
	darr->iarr = new_iarr;
	darr->strarr = new_strarr;
	darr->istrarr = new_istrarr;
}

void	__darr_double_size__(t_darr *darr)
{
	if (darr->type == DARR_INT)
		__darr_double_size_int_arr__(darr);
	if (darr->type == DARR_STR)
		__darr_double_size_str_arr__(darr);
	if (darr->type == DARR_INTSTR)
		__darr_double_size_intstr_arr__(darr);
	darr->size *= 2;
}
