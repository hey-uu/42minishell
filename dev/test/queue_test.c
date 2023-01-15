/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_test.c                                       :+:      :+:    :+:   */
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
	t_queue	*queue;

	queue = create_queue(10, QUEUE_INTSTR);
	queue_push_intstr(queue, 0, strdup("zero"));
	queue_push_intstr(queue, 1, strdup("one"));
	queue_show(queue);
	free(queue_pop_intstr(queue).str);
	queue_show(queue);
	queue_push_intstr(queue, 2, strdup("two"));
	queue_show(queue);
	destroy_queue(&queue);
	queue_show(queue);
#ifndef FSANITIZE_FLAG
	while (1)
	{
		system("leaks a.out");
		sleep(1);
	}
#endif
}