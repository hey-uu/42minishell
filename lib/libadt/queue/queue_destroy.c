/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:58:19 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/17 11:19:49 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "queue_internal.h"

void	queue_flush(t_queue *queue)
{
	char	*popped;

	if (queue->strarr)
	{
		while (queue->used_size > 0)
		{
			popped = queue_pop_str(queue);
			free(popped);
		}
	}
	queue->used_size = 0;
	queue->front = 0;
	queue->rear = 0;
}

void	destroy_queue(t_queue **queue)
{
	queue_flush(*queue);
	if ((*queue)->strarr)
		free((*queue)->strarr);
	if ((*queue)->iarr)
		free((*queue)->iarr);
	free(*queue);
	*queue = NULL;
}
