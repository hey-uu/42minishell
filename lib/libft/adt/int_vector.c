/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 09:33:55 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/07 18:41:02 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vector.h"
#include "libft.h"
#include <unistd.h>

t_ivector	ivec_create(int capacity)
{
	t_ivector	new;

	new = ft_malloc(sizeof(struct s_ivector));
	new->used_size = 0;
	new->capacity = capacity;
	new->array = ft_malloc(sizeof(int) * new->capacity);
	return (new);
}

void	ivec_destroy(t_ivector vector)
{
	free(vector->array);
	free(vector);
}

static void	ivec_double_array_size(t_ivector vector)
{
	int	new_capacity;
	int	*new_array;

	new_capacity = vector->capacity * 2;
	new_array = ft_malloc(sizeof(int) * new_capacity);
	ft_memcpy(new_array, vector->array, sizeof(int) * vector->used_size);
	free(vector->array);
	vector->capacity = new_capacity;
	vector->array = new_array;
}

static void	ivec_half_array_size(t_ivector vector)
{
	int	new_capacity;
	int	*new_array;

	new_capacity = vector->capacity / 2;
	new_array = ft_malloc(sizeof(int) * new_capacity);
	ft_memcpy(new_array, vector->array, sizeof(int) * vector->used_size);
	free(vector->array);
	vector->capacity = new_capacity;
	vector->array = new_array;
}

void	ivec_add(t_ivector vector, int data)
{
	if (vector->capacity <= vector->used_size)
		ivec_double_array_size(vector);
	vector->array[vector->used_size++] = data;
}

void	ivec_add_at(t_ivector vector, int idx, int data)
{
	int	i;

	if (idx > vector->used_size)
	{
		write(2, "ivec_add_at: out of index", 25);
		exit(1);
	}
	if (vector->capacity <= vector->used_size)
		ivec_double_array_size(vector);
	i = vector->used_size;
	while (--i >= idx)
		vector->array[i + 1] = vector->array[i];
	vector->array[idx] = data;
	vector->used_size++;
}

void	ivec_put(t_ivector vector, int idx, int data)
{
	if (idx >= vector->used_size)
	{
		write(2, "ivec_add_at: out of index", 25);
		exit(1);
	}
	vector->array[idx] = data;
}

int	ivec_get(t_ivector vector, int idx)
{
	if (idx >= vector->used_size)
	{
		write(2, "ivec_add_at: out of index", 25);
		exit(1);
	}
	return (vector->array[idx]);
}

void	ivec_remove(t_ivector vector)
{
	vector->used_size--;
	if (vector->capacity > vector->used_size * 2)
		ivec_half_array_size(vector);
}

void	ivec_remove_at(t_ivector vector, int idx)
{
	int	i;

	if (idx >= vector->used_size)
	{
		write(2, "ivec_add_at: out of index", 25);
		exit(1);
	}
	i = idx;
	while (idx < vector->used_size - 1)
	{
		vector->array[idx] = vector->array[idx + 1];
		idx++;
	}
	vector->used_size--;
	if (vector->capacity > vector->used_size * 2)
		ivec_half_array_size(vector);
}