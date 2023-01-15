/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:37:11 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/15 17:04:24 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

int	queue_pop_int(t_queue *queue)
{
	int	popped;

	popped = queue->iarr[queue->front];
	queue->front = (queue->front + 1) % queue->size;
	queue->used_size--;
	return (popped);
}

char	*queue_pop_str(t_queue *queue)
{
	char	*popped;

	popped = queue->strarr[queue->front];
	queue->front = (queue->front + 1) % queue->size;
	queue->used_size--;
	return (popped);
}

t_intstr	queue_pop_intstr(t_queue *queue)
{
	int		popped_int;
	char	*popped_str;

	popped_int = queue->iarr[queue->front];
	popped_str = queue->strarr[queue->front];
	queue->front = (queue->front + 1) % queue->size;
	queue->used_size--;
	return ((t_intstr){popped_int, popped_str});
}
