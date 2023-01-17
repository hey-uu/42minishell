/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_show.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 06:38:01 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/17 11:28:22 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_queue.h"
#include <stdio.h>

static void	print_line(void)
{
	printf("-----------------------------------------\n");
}

static void	print_basic_info(t_queue *queue)
{
	printf("size: %d, used_size: %d, ", queue->size, queue->used_size);
	printf("front: %d, rear: %d\n", queue->front, queue->rear);
}

static void	print_type(int queue_type)
{
	if (queue_type == QUEUE_INT_ONLY)
		printf("value data type : int\n");
	else if (queue_type == QUEUE_STR_ONLY)
		printf("value data type : string\n");
	else
		printf("value data type : {int, string}\n");
}

static void	print_all_content(t_queue *queue)
{
	int	i;

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
}

void	queue_show(t_queue *queue)
{
	if (!queue)
		return ;
	print_line();
	print_basic_info(queue);
	print_type(queue->type);
	print_all_content(queue);
	print_line();
}
