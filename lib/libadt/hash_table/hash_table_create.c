/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:38:17 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 21:46:34 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stddef.h>
#include "libft.h"
#include "hash_table.h"
#include <stdlib.h>
#include <stdio.h>

void	hash_table_initialize(t_hash_table *table)
{
	table->bucket_cnt = INITIAL_BUCKET_CNT;
	table->bucket_arr = ft_calloc(table->bucket_cnt, sizeof(t_hash_content *));
	table->entry_cnt = 0;
}

/**
 * @brief 
 * Create a new hash table with 'bucket_cnt' number of buckets.
 * Each value of bucket array is initialized as NULL pointer.
*/
t_hash_table	*hash_table_create(void)
{
	t_hash_table	*new;

	new = ft_malloc(sizeof(t_hash_table));
	hash_table_initialize(new);
	return (new);
}
