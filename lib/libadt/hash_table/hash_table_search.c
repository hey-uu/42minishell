/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_search.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:17:10 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 13:01:06 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table_internal.h"
#include "libft.h"

static void	debug_print(t_hash_content *target)
{
	printf("searching...\n");
	printf("key: %s\n", target->key);
	printf("pointer : %p\n", target);
	printf("next pointer : %p\n", target->next);
	if (target->next)
		printf("next key: %s\n\n", target->next->key);
	else
		printf("\n");
}

/**
 * @brief
 * Search for an entry from hash table's bucket array whose index matches with 
 * hash value of given key.
 * When 'search method' fails finding the entry, it returns a NULL pointer.
 * Make sure that both hash table and key must not be NULL.
*/
t_hash_content	*hash_table_search(t_hash_table *table, char *key, int bucket)
{
	t_hash_content	*target;

	target = table->bucket_arr[bucket];
	while (target)
	{
// debug_print(target);
		if (!ft_strncmp(target->key, key, ft_strlen(key) + 1))
			return (target);
		target = target->next;
	}
	return (target);
}
