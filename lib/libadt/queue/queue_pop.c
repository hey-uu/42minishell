/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:37:11 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/10 19:42:28 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue_internal.h"

int	queue_pop_int(t_queue *deq)
{
	int	popped;

	popped = deq->iarr[deq->front];
	deq->front = (deq->front + 1) % deq->size;
	deq->used_size--;
	return (popped);
}

char	*queue_pop_str(t_queue *deq)
{
	char	*popped;

	popped = deq->strarr[deq->front];
	deq->front = (deq->front + 1) % deq->size;
	deq->used_size--;
	return (popped);
}

t_intstr	queue_pop_intstr(t_queue *deq)
{
	int		popped_int;
	char	*popped_str;

	popped_int = deq->iarr[deq->front];
	popped_str = deq->strarr[deq->front];
	deq->front = (deq->front + 1) % deq->size;
	deq->used_size--;
	return ((t_intstr){popped_int, popped_str});
}
