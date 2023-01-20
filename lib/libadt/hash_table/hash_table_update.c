/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_update.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:21:23 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/20 17:41:05 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hash_table_internal.h"

/**
 * @brief
 * If there is a matching entry from hash table, then update method renews 
 * the content.
 * Otherwise, it inserts data to the hash table.
 * Make sure that both hash table and key must not be NULL.
*/
void	hash_table_update(t_hash_table *hash_table, char *key, void *content)
{
	t_hash_content	*target;
	int				bucket;

	bucket = hash_bucket(key, hash_table->bucket_cnt);
	target = hash_table_search(hash_table, key, bucket);
	if (!target)
		hash_table_insert(hash_table, key, content);
	else
	{
		free(key);
		free(target->content);
		target->content = content;
	}
}
