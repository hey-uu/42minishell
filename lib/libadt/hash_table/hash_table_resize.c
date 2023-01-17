/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_resize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:45:17 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/17 11:52:22 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hash_table_internal.h"
#include "libft.h"

static void	__hash_table_move_entries__(\
			t_hash_table *table, t_hash_content **old_arr, int old_cnt)
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
			bucket = hash_bucket(target->key, table->bucket_cnt);
printf("move %s from bucket %d to new bucket %d\n", target->key, i, bucket);
			__hash_table_insert_entry__(table->bucket_arr, target, bucket);
			target = next;
		}
	}
	free(old_arr);
}

void	__hash_table_grow__(t_hash_table *table)
{
	t_hash_content	**old_bucket_arr;
	int				old_bucket_cnt;
	int				i;

	old_bucket_arr = table->bucket_arr;
	old_bucket_cnt = table->bucket_cnt;
	table->bucket_cnt = old_bucket_cnt * GROW_MULTIPLIER;
	table->bucket_arr = ft_malloc(table->bucket_cnt * sizeof(t_hash_content));
printf("growing...size %d to %d\n", old_bucket_cnt, table->bucket_cnt);
	i = -1;
	while (++i < table->bucket_cnt)
	{
		table->bucket_arr[i] = NULL;
	}
	__hash_table_move_entries__(table, old_bucket_arr, old_bucket_cnt);
}

void	__hash_table_shrink__(t_hash_table *table)
{
	t_hash_content	**old_bucket_arr;
	int				old_bucket_cnt;
	int				i;

printf("shrinking...\n");
	old_bucket_arr = table->bucket_arr;
	old_bucket_cnt = table->bucket_cnt;
	table->bucket_cnt = old_bucket_cnt / SHRINK_DIVISOR;
	table->bucket_arr = ft_malloc(table->bucket_cnt * sizeof(t_hash_content));
	i = -1;
	while (++i < table->bucket_cnt)
	{
		table->bucket_arr[i] = NULL;
	}
	__hash_table_move_entries__(table, old_bucket_arr, old_bucket_cnt);
}
