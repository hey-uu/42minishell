/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:38:17 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/14 21:54:28 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stddef.h>
#include "libft.h"
#include "hash_table.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief 
 * Create a new hash table with 'bucket_cnt' number of buckets.
 * Each value of bucket array is initialized as NULL pointer.
*/
t_hash_table	*hash_table_create(void)
{
	t_hash_table	*new;
	int				i;

	new = ft_malloc(sizeof(t_hash_table));
	new->bucket_cnt = INITIAL_BUCKET_CNT;
	new->bucket_arr = ft_malloc(new->bucket_cnt * sizeof(t_hash_content *));
	new->entry_cnt = 0;
	i = -1;
	while (++i < new->bucket_cnt)
	{
		new->bucket_arr[i] = NULL;
	}
	return (new);
}
