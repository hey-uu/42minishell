/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:18:33 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/14 23:05:54 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libadt.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>

#define ENTRY_CNT 11

static char	*key[] = {
	"hyeyun", // 1
	"yoenhkim", // 2
	"donghyle", // 3
	"dahkang", // 4
	"minseok2", // 5
	"hello", // 6
	"this", // 7
	"is", // 8
	"so", // 9
	"funny", // 10
	"?" // 11
};

static char	*content[] = {
	"23 years old", // 1
	"so funny", // 2
	"notebook lover", // 3
	"studying english hard", // 4
	"philosopher study team", // 5 
	"greeting", // 6
	"content_this", // 7
	"content_is", // 8
	"content_so", // 9
	"content_funny", // 10
	"content_?" // 11
};


int	main(void)
{
	t_hash_table	*tab;
	t_hash_content	*target;
	int				i, bucket;

	tab = hash_table_create();
	i = -1;
	printf("================== [test] : hash and insert ==================\n");
	while (++i < ENTRY_CNT)
	{
		bucket =  hash_bucket(key[i], tab->bucket_cnt);
		printf("hash: %d\n", bucket);
		printf("key: %s, content: %s\n\n", key[i], content[i]);
		hash_table_insert(tab, ft_strdup(key[i]), ft_strdup(content[i]));
		assert(tab->entry_cnt == (i  + 1));
	}
	printf("insert method --> ok\n\n");
	printf("======================= [test] : search ======================\n");
	while (--i >= 0)
	{
		bucket = hash_bucket(key[i], tab->bucket_cnt);
		target = hash_table_search(tab, key[i], bucket);
		assert(target != NULL);
		printf("key: %s, content: %s\n\n", key[i], (char *)target->content);
		assert(!ft_strncmp(target->content, content[i], ft_strlen(content[i]) + 1));
	}
	printf("search method --> ok\n\n");
	printf("======================= [test] : update ======================\n");
	while (++i < ENTRY_CNT)
	{
		hash_table_update(tab, key[i], ft_strdup(content[ENTRY_CNT - i - 1]));
		bucket = hash_bucket(key[i], tab->bucket_cnt);
		target = hash_table_search(tab, key[i], bucket);
		printf("key: %s, updated content: %s\n\n", \
											key[i], (char *)target->content);
		assert(!ft_strncmp(target->content, \
							content[ENTRY_CNT - i - 1], \
							ft_strlen(content[ENTRY_CNT - i - 1]) + 1));
		assert(tab->entry_cnt == ENTRY_CNT);
	}
	printf("update method --> ok\n\n");
	printf("======================= [test] : delete =======================\n");
	while (--i > 0)
	{
		hash_table_delete(tab, key[i]);
		assert(tab->entry_cnt == i);
		bucket = hash_bucket(key[i], tab->bucket_cnt);
		assert(!hash_table_search(tab, key[i], bucket));
		printf("%s is gone!\n", key[i]);
	}
	printf("======================= [test] : destroy ======================\n");
	hash_table_destroy(tab);
	printf("destroy method --> ok\n\n");
	while (1)
	{
		system("leaks hash_test");
		sleep(1);
	}
}