/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_env_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:07:28 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 09:49:53 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager_internal.h"
#include "libft.h"

char	*__env_get__(t_env_tab *table, char *variable)
{
	t_hash_content	*entry;
	int				bucket;

	if (!variable || !table->bucket_cnt)
		return (NULL);
	bucket = hash_bucket(variable, table->bucket_cnt);
	entry = hash_table_search(table, variable, bucket);
	if (entry)
		return ((char *)entry->content);
	return (NULL);
}

char	**__env_tab_to_arr__(t_env_tab *table)
{
	char			**arr;
	t_hash_content	*cur;
	int				i;
	int				j;

	arr = ft_malloc(sizeof(char *) * (table->bucket_cnt) + 1);
	arr[table->bucket_cnt] = NULL;
	j = 0;
	i = 0;
	while (i < table->bucket_cnt)
	{
		cur = table->bucket_arr[i];
		while (cur)
		{
			arr[j++] = cur->content;
			cur = cur->next;
		}
		i++;
	}
	return (arr);
}
