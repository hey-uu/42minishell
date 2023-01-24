/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:16:39 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/24 00:44:56 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_queue.h"
#include "libft.h"

void	init_queue(t_queue *queue, int initial_size, int type)
{
	queue->type = type;
	queue->size = initial_size;
	queue->used_size = 0;
	queue->front = 0;
	queue->rear = 0;
	if (type == QUEUE_INT_ONLY || type == QUEUE_INTSTR)
		queue->iarr = ft_malloc(queue->size * sizeof(int));
	else
		queue->iarr = NULL;
	if (type == QUEUE_STR_ONLY || type == QUEUE_INTSTR)
		queue->strarr = ft_calloc(queue->size, sizeof(char *));
	else
		queue->strarr = NULL;
}

t_queue	*create_queue(int initial_size, int type)
{
	t_queue	*queue;

	queue = ft_malloc(sizeof(t_queue));
	init_queue(queue, initial_size, type);
	return (queue);
}
