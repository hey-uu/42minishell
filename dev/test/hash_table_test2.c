/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_test2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:18:33 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/14 22:27:37 by hyeyukim         ###   ########.fr       */
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

void	show_hash_table(t_hash_table *table);

int	main(void)
{
	t_hash_table	*tab;
	int				i, bucket;

	tab = hash_table_create();
	i = -1;
	printf("================== [test] : hash and insert ==================\n");
	while (++i < ENTRY_CNT)
	{
		bucket =  hash_bucket(key[i], tab->bucket_cnt);
		printf("hash: %d\n", bucket);
		printf("key: %s, content: %s\n\n", key[i], content[i]);
		hash_table_insert(tab, ft_strdup(key[i]), ft_strdup(content[i]), bucket);
		assert(tab->entry_cnt == (i  + 1));
	}
	printf("insert method --> ok\n\n");
	show_hash_table(tab);
	printf("======================= [test] : destroy ======================\n");
	hash_table_destroy(tab);
	printf("destroy method --> ok\n\n");
	while (1)
	{
		system("leaks hash_test");
		sleep(1);
	}
}