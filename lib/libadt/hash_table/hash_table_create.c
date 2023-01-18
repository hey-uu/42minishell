/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:38:17 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 15:39:07 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table_internal.h"
#include "libft.h"

void	hash_table_init(t_hash_table *table)
{
	table->bucket_cnt = INITIAL_BUCKET_CNT;
	table->bucket_arr = ft_calloc(table->bucket_cnt, sizeof(t_hash_content *));
	table->entry_cnt = 0;
}

/**
 * @brief 
 * Create a new hash table with 'bucket_cnt' number of buckets.
 * Each value of bucket array is initd as NULL pointer.
*/
t_hash_table	*hash_table_create(void)
{
	t_hash_table	*new;

	new = ft_malloc(sizeof(t_hash_table));
	hash_table_init(new);
	return (new);
}
