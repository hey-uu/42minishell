/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_env_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:07:28 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 20:07:17 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager_internal.h"

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

static char	*__join_defined_variable__(char *variable, char *value)
{
	const int	var_len = ft_strlen(variable);
	int			val_len;
	int			line_len;
	char		*line;

	line_len = var_len;
	val_len = ft_strlen(value);
	line_len += (1 + val_len);
	line = ft_malloc(sizeof(char) * (line_len + 1));
	ft_strlcpy(line, variable, var_len + 1);
	ft_strlcpy(line + var_len, "=", 2);
	ft_strlcpy(line + var_len + 1, value, val_len + 1);
	return (line);
}

char	**__env_get_defined_variable_list__(t_env_tab *table)
{
	char			**arr;
	t_hash_content	*cur;
	int				i;
	int				j;

	arr = ft_malloc(sizeof(char *) * (table->entry_cnt + 1));
	i = 0;
	j = 0;
	while (i < table->bucket_cnt)
	{
		cur = table->bucket_arr[i];
		while (cur)
		{
			if (cur->content)
			{
				arr[j] = __join_defined_variable__(cur->key, cur->content);
				j++;
			}
			cur = cur->next;
		}
		i++;
	}
	arr[j] = NULL;
	return (arr);
}

static char	*__join_marked_variable__(char *variable, char *value)
{
	const int	var_len = ft_strlen(variable);
	int			val_len;
	int			line_len;
	char		*line;

	line_len = var_len;
	if (value)
	{
		val_len = ft_strlen(value);
		line_len += (3 + val_len);
	}
	line = ft_malloc(sizeof(char) * (line_len + 1));
	ft_strlcpy(line, variable, var_len + 1);
	if (value)
	{
		ft_strlcpy(line + var_len, "=\"", 3);
		ft_strlcpy(line + var_len + 2, value, val_len + 1);
		ft_strlcpy(line + var_len + 2 + val_len, "\"", 2);
	}
	return (line);
}

char	**__env_get_marked_variable_list__(t_env_tab *table)
{
	char			**arr;
	t_hash_content	*cur;
	int				i;
	int				j;

	arr = ft_malloc(sizeof(char *) * (table->entry_cnt + 1));
	j = 0;
	i = 0;
	while (i < table->bucket_cnt)
	{
		cur = table->bucket_arr[i];
		while (cur)
		{
			arr[j] = __join_marked_variable__(cur->key, cur->content);
			j++;
			cur = cur->next;
		}
		i++;
	}
	arr[j] = NULL;
	return (arr);
}
