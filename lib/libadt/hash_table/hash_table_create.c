/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:38:17 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/14 20:59:11 by hyeyukim         ###   ########.fr       */
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

static void	hash_table_insert_entry(\
	t_hash_content **bucket_array, t_hash_content *entry)
{
	entry->next = *bucket_array;
	if (*bucket_array)
		(*bucket_array)->prev = entry;
	*bucket_array = entry;
}

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
			printf("move %s to new bucket %d\n", target->key, bucket);
			hash_table_insert_entry(&hash_table->bucket_arr[bucket], target);
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

/**
 * @brief
 * Search for an entry from hash table's bucket array whose index matches with 
 * hash value of given key.
 * When search method fails finding the entry, it returns a NULL pointer.
 * Make sure that both hash table and key must not be NULL.
*/
t_hash_content	*hash_table_search(t_hash_table *hash_table, char *key)
{
	const int		bucket_idx = hash_bucket(key, hash_table->bucket_cnt);
	t_hash_content	*target;
	
	target = hash_table->bucket_arr[bucket_idx];
	while (target)
	{
		printf("searching... %s\n", target->key);
		printf("pointer : %p\n", target);
		printf("next pointer : %p\n", target->next);
		if (target->next)
			printf("next key: %s\n\n", target->next->key);
		printf("\n");
		if (!ft_strncmp(target->key, key, ft_strlen(key) + 1))
			return (target);
		target = target->next;
	}
	return (target);
}

/**
 * @brief
 * Insert data to the hash table's bucket matching with given key.
 * This insert method use is premised on the assumption that the given key hasn't
 * been stored in the hash table previously.
 * Make sure that both hash table and key must not be NULL.
*/
void	hash_table_insert(t_hash_table *hash_table, char *key, void *content)
{
	t_hash_content	*new_entry;
	int				bucket_idx;

	printf("inserting...%s, %s\n", key, (char *)content);
	if (hash_table->entry_cnt >= hash_table->bucket_cnt * LOAD_FACTOR)
		hash_table_grow(hash_table);
	bucket_idx = hash_bucket(key, hash_table->bucket_cnt);
	new_entry = ft_malloc(sizeof(t_hash_content));
	new_entry->key = key;
	new_entry->content = content;
	new_entry->prev = NULL;
	new_entry->next = NULL;
	hash_table_insert_entry(&hash_table->bucket_arr[bucket_idx], new_entry);
	hash_table->entry_cnt++;
}

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

	target = hash_table_search(hash_table, key);
	if (!target)
		hash_table_insert(hash_table, key, content);
	else
	{
		free(target->content);
		target->content = content;
	}
}

static void	hash_table_delete_entry(\
	t_hash_table *hash_table, t_hash_content *target, int bucket)
{
	printf("gonna deleted soon... %s\n", target->key);
	if (!target->prev)
		hash_table->bucket_arr[bucket] = target->next;
	else
		target->prev->next = target->next;
	if (target->next)
		target->next->prev = target->prev;
	free(target->key);
	free(target->content);
	free(target);
	hash_table->entry_cnt--;
}

/**
 * @brief
 * First search for the matching entry from hash table.
 * If delete method finds the matching entry, it deletes the content 
 * from the hash table. Otherwise, nothing happens.
 * Make sure that both hash table and key must not be NULL.
*/
void	hash_table_delete(t_hash_table *hash_table, char *key)
{
	t_hash_content	*target;

	if (hash_table->entry_cnt >= INITIAL_BUCKET_CNT && \
		hash_table->entry_cnt <= hash_table->bucket_cnt * LOAD_FACTOR)
	{
		printf("shrinking...\n");
		hash_table_shrink(hash_table);
	}
	printf("want to delete %s\n", key);
	target = hash_table_search(hash_table, key);
	if (!target)
		return ;
	hash_table_delete_entry(hash_table, target, hash_bucket(target->key, hash_table->bucket_cnt));
}

/**
 * @brief
 * Delete every entry of the hash table.
 * Also free the bucket array of the hash table and the hash table itself.
*/
void	hash_table_destroy(t_hash_table *hash_table)
{
	int				i;
	t_hash_content	*next;
	t_hash_content	*target;
	
	i = -1;
	while (++i < hash_table->bucket_cnt)
	{
		target = hash_table->bucket_arr[i];
		while (target)
		{
			next = target->next;
			hash_table_delete_entry(hash_table, target, i);
			target = next;
		}
	}
	free(hash_table->bucket_arr);
	free(hash_table);
}
