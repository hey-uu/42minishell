/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_generate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:16:39 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/10 19:42:45 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue_internal.h"
#include <stdlib.h>
#include "libft.h"

t_queue	*create_queue(int initial_size, int type)
{
	t_queue	*queue;

	queue = ft_malloc(sizeof(t_queue));
	queue->type = type;
	queue->size = initial_size;
	queue->used_size = 0;
	queue->front = 0;
	queue->rear = 0;
	if (type == QUEUE_INT_ONLY || type == QUEUE_INTSTR)
		queue->iarr = ft_malloc(sizeof(int) * queue->size);
	else
		queue->iarr = NULL;
	if (type == QUEUE_STR_ONLY || type == QUEUE_INTSTR)
		queue->strarr = ft_malloc(sizeof(char *) * queue->size);
	else
		queue->strarr = NULL;
	return (queue);
}

void	destroy_queue(t_queue *queue)
{
	int	i;

	if (queue->strarr)
	{
		i = -1;
		while (++i < queue->used_size)
			free(queue->strarr[i]);
		free(queue->strarr);
	}
	if (queue->iarr)
		free(queue->iarr);
	free(queue);
}

void	queue_double_size_iarr(t_queue *queue)
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

void	queue_double_size_strarr(t_queue *queue)
{
	char	**new;
	int		i;

	new = ft_malloc(sizeof(char *) * queue->size * 2);
	if (queue->used_size != 0)
	{
		i = -1;
		while (++i < queue->used_size)
			new[i] = queue->strarr[(queue->front + i) % queue->size];
	}
	free(queue->strarr);
	queue->strarr = new;
}

int	queue_double_size(t_queue *queue)
{
	if (queue->type == QUEUE_INT_ONLY || queue->type == QUEUE_INTSTR)
		queue_double_size_iarr(queue);
	if (queue->type == QUEUE_STR_ONLY || queue->type == QUEUE_INTSTR)
		queue_double_size_strarr(queue);
	queue->front = 0;
	queue->rear = queue->used_size;
	queue->size *= 2;
	return (1);
}