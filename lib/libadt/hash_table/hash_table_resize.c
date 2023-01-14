/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_resize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:45:17 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/14 22:11:20 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"
#include <stdlib.h>
#include "libft.h"

static void	hash_table_move_entries(\
	t_hash_table *hash_table, t_hash_content **old_arr, int old_cnt)
{
	t_hash_content	*target;
	t_hash_content	*next;
	int				i;
	int				bucket;

	printf("moving entries...\n");
	i = -1;
	while (++i < old_cnt)
	{
		target = old_arr[i];
		while (target)
		{
			next = target->next;
			bucket = hash_bucket(target->key, hash_table->bucket_cnt);
			printf("move %s from bucket %d to new bucket %d\n", target->key, i, bucket);
			hash_table_insert_entry(hash_table->bucket_arr, target, bucket);
			target = next;
		}
	}
	free(old_arr);
}

void	hash_table_grow(t_hash_table *hash_table)
{
	t_hash_content	**old_bucket_arr;
	int				old_bucket_cnt;
	int				i;

	old_bucket_arr = hash_table->bucket_arr;
	old_bucket_cnt = hash_table->bucket_cnt;
	hash_table->bucket_cnt = old_bucket_cnt * GROW_MULTIPLIER;
	hash_table->bucket_arr = ft_malloc(\
							hash_table->bucket_cnt * sizeof(t_hash_content));
	printf("growing...size %d to %d\n", old_bucket_cnt, hash_table->bucket_cnt);
	i = -1;
	while (++i < hash_table->bucket_cnt)
	{
		hash_table->bucket_arr[i] = NULL;
	}
	hash_table_move_entries(hash_table, old_bucket_arr, old_bucket_cnt);
}

void	hash_table_shrink(t_hash_table *hash_table)
{
	t_hash_content	**old_bucket_arr;
	int				old_bucket_cnt;
	int				i;

	printf("shrinking...\n");
	old_bucket_arr = hash_table->bucket_arr;
	old_bucket_cnt = hash_table->bucket_cnt;
	hash_table->bucket_cnt = old_bucket_cnt / SHRINK_DIVISOR;
	hash_table->bucket_arr = ft_malloc(\
							hash_table->bucket_cnt * sizeof(t_hash_content));
	i = -1;
	while (++i < hash_table->bucket_cnt)
	{
		hash_table->bucket_arr[i] = NULL;
	}
	hash_table_move_entries(hash_table, old_bucket_arr, old_bucket_cnt);
}

