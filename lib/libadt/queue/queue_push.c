/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:29:27 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/17 11:52:42 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue_internal.h"

void	queue_push_int(t_queue *queue, int new_data)
{
	if (queue->used_size == queue->size)
		__queue_double_size__(queue);
	queue->iarr[queue->rear] = new_data;
	queue->rear = (queue->rear + 1) % queue->size;
	queue->used_size++;
}

void	queue_push_str(t_queue *queue, char *new_data)
{
	if (queue->used_size == queue->size)
		__queue_double_size__(queue);
	queue->strarr[queue->rear] = new_data;
	queue->rear = (queue->rear + 1) % queue->size;
	queue->used_size++;
}

void	queue_push_intstr(t_queue *queue, int idata, char *sdata)
{
	if (queue->used_size == queue->size)
		__queue_double_size__(queue);
	queue->strarr[queue->rear] = sdata;
	queue->iarr[queue->rear] = idata;
	queue->rear = (queue->rear + 1) % queue->size;
	queue->used_size++;
}

void	queue_push_strs(t_queue *queue, char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
	{
		queue_push_str(queue, strs[i]);
	}
}
