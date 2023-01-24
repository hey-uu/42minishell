/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darr_show.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:38:01 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/17 11:28:22 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_dynamic_array.h"
#include <stdio.h>

static void	print_line(void)
{
	printf("-----------------------------------------\n");
}

static void	print_basic_info(t_darr *darr)
{
	printf("size: %d, used_size: %d, ", darr->size, darr->used_size);
}

static void	print_type(int darr_type)
{
	if (darr_type == DARR_INT)
		printf("value data type : int\n");
	else if (darr_type == DARR_STR)
		printf("value data type : string\n");
	else
		printf("value data type : {int, string}\n");
}

static void	print_all_content(t_darr *darr)
{
	int	i;

	printf("value | id : data\n");
	i = -1;
	while (++i < darr->size)
	{
		if (darr->type == DARR_INT)
			printf("       %d : %d\n", i, darr->iarr[i]);
		if (darr->type == DARR_INTSTR)
			printf("       %d : (%d, %s), (%d, %s)\n", \
					i, darr->iarr[i], darr->strarr[i], \
					darr->istrarr[i].num, darr->istrarr[i].str);
		if (darr->type == DARR_STR)
			printf("       %d : %s\n", i, darr->strarr[i]);
	}
}

void	darr_show(t_darr *darr)
{
	if (!darr)
		return ;
	print_line();
	print_basic_info(darr);
	print_type(darr->type);
	print_all_content(darr);
	print_line();
}
