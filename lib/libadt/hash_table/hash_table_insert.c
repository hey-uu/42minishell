/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_insert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:10:18 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/14 21:56:57 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table.h"
#include "libft.h"
#include <stdlib.h>

void	hash_table_insert_entry(\
	t_hash_content **bucket_arr, t_hash_content *entry, int bucket)
{
	entry->prev = NULL;
	entry->next = bucket_arr[bucket];
	if (bucket_arr[bucket])
		bucket_arr[bucket]->prev = entry;
	bucket_arr[bucket] = entry;
}

static t_hash_content	*hash_table_create_content(char *key, void *content)
{
	t_hash_content	*new;

	new = ft_malloc(sizeof(t_hash_content));
	new->key = key;
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return(new);
}

/**
 * @brief
 * Insert data to the hash table's bucket matching with given key.
 * This insert method use is premised on the assumption that the given key hasn't
 * been stored in the hash table previously.
 * Make sure that both hash table and key must not be NULL.
*/
void	hash_table_insert(\
		t_hash_table *table, char *key, void *content, int bucket)
{
	t_hash_content	*new_entry;

	printf("inserting...%s, %s\n", key, (char *)content);
	if (table->entry_cnt >= table->bucket_cnt * LOAD_FACTOR)
	{
		hash_table_grow(table);
		bucket = hash_bucket(key, table->bucket_cnt);
	}
	new_entry = hash_table_create_content(key, content);
	hash_table_insert_entry(table->bucket_arr, new_entry, bucket);
	table->entry_cnt++;
}