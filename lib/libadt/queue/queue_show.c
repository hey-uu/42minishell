/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_show.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:38:01 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/15 17:36:40 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <stdio.h>

void	queue_show(t_queue *queue)
{
	int	i;

	if (!queue)
		return ;
	printf("-----------------------------------------\n");
	printf("size: %d, used_size: %d, front: %d, rear: %d\n", \
		queue->size, queue->used_size, queue->front, queue->rear);
	if (queue->type == QUEUE_INT_ONLY)
		printf("value data type : int\n");
	else if (queue->type == QUEUE_STR_ONLY)
		printf("value data type : string\n");
	else
		printf("value data type : {int, string}\n");
	printf("val| id : data\n");
	i = -1;
	while (++i < queue->size)
	{
		if (queue->type == QUEUE_INT_ONLY || queue->type == QUEUE_INTSTR)
			printf("       %d : %d\n", \
					(queue->front + i) % queue->size, \
					queue->iarr[(queue->front + i) % queue->size]);
		if (queue->type == QUEUE_STR_ONLY || queue->type == QUEUE_INTSTR)
			printf("       %d : %s\n", \
					(queue->front + i) % queue->size, \
					queue->strarr[(queue->front + i) % queue->size]);
	}
	printf("-----------------------------------------\n");
}
