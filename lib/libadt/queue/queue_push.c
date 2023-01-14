/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:29:27 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/14 11:43:39 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	queue_push_int(t_queue *queue, int new_data)
{
	if (queue->used_size == queue->size)
		queue_double_size(queue);
	queue->iarr[queue->rear] = new_data;
	queue->rear = (queue->rear + 1) % queue->size;
	queue->used_size++;
}

void	queue_push_str(t_queue *queue, char *new_data)
{
	if (queue->used_size == queue->size)
		queue_double_size(queue);
	queue->strarr[queue->rear] = new_data;
	queue->rear = (queue->rear + 1) % queue->size;
	queue->used_size++;
}

void	queue_push_intstr(t_queue *queue, int idata, char *sdata)
{
	if (queue->used_size == queue->size)
		queue_double_size(queue);
	queue->strarr[queue->rear] = sdata;
	queue->iarr[queue->rear] = idata;
	queue->rear = (queue->rear + 1) % queue->size;
	queue->used_size++;
}
