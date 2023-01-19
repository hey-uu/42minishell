/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:59:34 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/19 18:23:07 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "t_queue.h"

int	queue_get_int(t_queue *queue, int i)
{
	int	idx;

	idx = (queue->front + i) % queue->size;
	return (queue->iarr[idx]);
}

char	*queue_get_str(t_queue *queue, int i)
{
	int	idx;

	idx = (queue->front + i) % queue->size;
	return (queue->strarr[idx]);
}

t_intstr	queue_get_intstr(t_queue *queue, int i)
{
	int	idx;

	idx = (queue->front + i) % queue->size;
	return ((t_intstr){queue->iarr[idx], queue->strarr[idx]});
}

int	queue_get_idx(t_queue *queue, int i)
{
	return ((queue->front + i) % queue->size);
}