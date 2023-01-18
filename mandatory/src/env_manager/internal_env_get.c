/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_env_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:07:28 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 13:25:54 by hyeyukim         ###   ########.fr       */
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

char	*__join_variable_and_value__(char *variable, char *value)
{
	const int	var_len = ft_strlen(variable);
	char		*line;
	int			val_len;
	int			line_len;

	line_len = var_len + 1;
	if (value)
	{
		val_len = ft_strlen(value);
		line_len += val_len;
	}
	line = ft_malloc(sizeof(char) * (line_len + 1));
	ft_strlcpy(line, variable, var_len + 1);
	ft_strlcpy(line + var_len, "=", 2);
	if (value)
		ft_strlcpy(line + var_len + 1, value, val_len + 1);
	return (line);
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
			arr[j] = __join_variable_and_value__(cur->key, cur->content);
			cur = cur->next;
		}
		i++;
	}
	return (arr);
}
