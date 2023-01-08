/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:46:58 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/09 06:52:58 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/includes/queue.h"

int	main(void)
{
	t_queue	*queue;

	queue = create_queue(10, QUEUE_INTSTR);
	queue_push_rear_intstr(queue, 0, "zero");
	queue_push_rear_intstr(queue, 1, "one");
	queue_show(queue);
	queue_pop_front_intstr(queue);
	queue_show(queue);
	queue_push_rear_intstr(queue, 2, "two");
	queue_show(queue);
	queue_pop_front_intstr(queue);
	queue_pop_front_intstr(queue);
	queue_show(queue);
}