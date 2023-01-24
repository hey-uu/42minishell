/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:10:18 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 00:42:26 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hash_table_internal.h"
#include "libft.h"

void	__hash_table_insert_entry__(\
		t_hash_content **bucket_arr, t_hash_content *entry, int bucket)
{
	entry->prev = NULL;
	entry->next = bucket_arr[bucket];
	if (bucket_arr[bucket])
		bucket_arr[bucket]->prev = entry;
	bucket_arr[bucket] = entry;
}

static t_hash_content	*__hash_table_create_content__(char *key, void *content)
{
	t_hash_content	*new;

	new = ft_malloc(sizeof(t_hash_content));
	new->key = key;
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/**
 * @brief
 * Insert data to the hash table's bucket matching with given key.
 * This insert method use is premised on the assumption that the given key hasn't
 * been stored in the hash table previously.
 * Make sure that both hash table and key must not be NULL.
*/
void	hash_table_insert(t_hash_table *table, char *key, void *content)
{
	t_hash_content	*new_entry;
	int				bucket;

	if (table->entry_cnt >= table->bucket_cnt * LOAD_FACTOR)
		__hash_table_grow__(table);
	bucket = hash_bucket(key, table->bucket_cnt);
	new_entry = __hash_table_create_content__(key, content);
	__hash_table_insert_entry__(table->bucket_arr, new_entry, bucket);
	table->entry_cnt++;
}
