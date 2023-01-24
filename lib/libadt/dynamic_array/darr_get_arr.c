/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darr_get_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:32:36 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/24 07:35:51 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include "t_dynamic_array.h"

int	*darr_get_int_arr(t_darr *darr)
{
	int	*arr;
	int	i;

	arr = ft_malloc(sizeof(int) * (darr->used_size));
	i = 0;
	while (i < darr->used_size)
	{
		arr[i] = darr->iarr[i];
		i++;
	}
	return (arr);
}

char	**darr_get_str_arr(t_darr *darr)
{
	char	**arr;
	int		i;

	arr = ft_malloc(sizeof(char *) * (darr->used_size + 1));
	i = 0;
	while (i < darr->used_size)
	{
		arr[i] = darr->strarr[i];
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

t_intstr	*darr_get_intstr_arr(t_darr *darr)
{
	t_intstr	*arr;
	int			i;

	arr = ft_malloc(sizeof(t_intstr) * (darr->used_size + 1));
	i = 0;
	while (i < darr->used_size)
	{
		arr[i] = darr->istrarr[i];
		i++;
	}
	arr[i] = (t_intstr){0, NULL};
	return (arr);
}
