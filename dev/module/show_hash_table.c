/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_hash_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:19:48 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/14 22:38:20 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libadt.h"

void	show_hash_table(t_hash_table *table)
{
	int				i;
	t_hash_content	*content;

	i = -1;
	printf("\n============= hash table ==============\n");
	while (++i < table->bucket_cnt)
	{
		content = table->bucket_arr[i];
		if (content)
			printf("\nhash : %d\n", i);
		while (content)
		{
			printf("key: %s, content: %s\n", content->key, (char *)content->content);
			content = content->next;
		}
	}
	printf("=======================================\n\n");
}
