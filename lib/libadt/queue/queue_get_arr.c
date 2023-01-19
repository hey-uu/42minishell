/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_get_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:32:36 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/19 19:56:20 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include "queue_internal.h"

int	*queue_get_int_arr(t_queue *queue)
{
	int	*arr;
	int	i;

	arr = ft_malloc(sizeof(int) * (queue->used_size));
	i = 0;
	while (i < queue->used_size)
	{
		arr[i] = queue_get_int(queue, i);
		i++;
	}
	return (arr);
}

char	**queue_get_str_arr(t_queue *queue)
{
	char	**arr;
	char	*str;
	int		i;

	arr = ft_malloc(sizeof(char *) * (queue->used_size + 1));
	i = 0;
	while (i < queue->used_size)
	{
		str = queue_get_str(queue, i);
		if (!str)
			arr[i] = NULL;
		else
			arr[i] = ft_strdup(str);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

t_intstr	*queue_get_intstr_arr(t_queue *queue)
{
	t_intstr	*arr;
	char		*str;
	int			i;

	arr = ft_malloc(sizeof(t_intstr) * (queue->used_size + 1));
	i = 0;
	while (i < queue->used_size)
	{
		arr[i].num = queue_get_int(queue, i);
		str = queue_get_str(queue, i);
		if (!str)
			arr[i].str = NULL;
		else
			arr[i].str = ft_strdup(str);
		i++;
	}
	arr[i] = (t_intstr){0, NULL};
	return (arr);
}
