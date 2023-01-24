/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   darr_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:46:58 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/15 17:47:45 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libadt.h"
#include <unistd.h>

int	main(void)
{
	t_darr	*darr;

	darr = create_dynamic_array(10, DARR_INTSTR);
	darr_push_intstr(darr, 0, strdup("zero"));
	darr_push_intstr(darr, 1, strdup("one"));
	darr_show(darr);
	free(darr_pop_intstr(darr).str);
	darr_show(darr);
	darr_push_intstr(darr, 2, strdup("two"));
	darr_show(darr);
	destroy_darr(&darr);
	darr_show(darr);
#ifndef FSANITIZE_FLAG
	while (1)
	{
		system("leaks a.out");
		sleep(1);
	}
#endif
}