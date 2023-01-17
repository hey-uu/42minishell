/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_internal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:07:28 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/17 12:19:03 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager_internal.h"
#include "libft.h"

t_env_tab	*__env_table_initialize__(t_env_tab *table, char **envp)
{
	char	*key;
	char	*value;
	size_t	i;
	size_t	j;

	if (!envp)
		return (NULL);
	hash_table_initialize(table);
	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		key = ft_strndup(envp[i], j);
		value = ft_strdup(&envp[i][j + 1]);
		hash_table_insert(table, key, value);
		i++;
	}
	return (table);
}

t_env_tab	*__env_set__(t_env_tab *table, char *variable, char *value)
{
	if (!variable)
		return (NULL);
	hash_table_update(table, variable, value);
	return (table);
}

t_env_tab	*__env_unset__(t_env_tab *table, char *variable)
{
	if (!variable)
		return (NULL);
	hash_table_delete(table, variable);
	return (table);
}

char	*__env_get__(t_env_tab *table, char *variable)
{
	t_hash_content	*entry;
	int				bucket;

	if (!variable)
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
