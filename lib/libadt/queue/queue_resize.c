/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_resize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:19:04 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/17 11:50:05 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_queue.h"
#include "libft.h"

void	__queue_double_size_iarr__(t_queue *queue)
{
	int	*new;
	int	i;

	new = ft_malloc(sizeof(int) * queue->size * 2);
	if (queue->used_size != 0)
	{
		i = -1;
		while (++i < queue->used_size)
			new[i] = queue->iarr[(queue->front + i) % queue->size];
	}
	free(queue->iarr);
	queue->iarr = new;
}

void	__queue_double_size_strarr__(t_queue *queue)
{
	char	**new;
	int		i;

	new = ft_calloc(queue->size * 2, sizeof(char *));
	if (queue->used_size != 0)
	{
		i = -1;
		while (++i < queue->used_size)
			new[i] = queue->strarr[(queue->front + i) % queue->size];
	}
	free(queue->strarr);
	queue->strarr = new;
}

int	__queue_double_size__(t_queue *queue)
{
	if (queue->type == QUEUE_INT_ONLY || queue->type == QUEUE_INTSTR)
		__queue_double_size_iarr__(queue);
	if (queue->type == QUEUE_STR_ONLY || queue->type == QUEUE_INTSTR)
		__queue_double_size_strarr__(queue);
	queue->front = 0;
	queue->rear = queue->used_size;
	queue->size *= 2;
	return (1);
}
