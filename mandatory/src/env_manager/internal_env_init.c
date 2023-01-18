/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_env_init.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 03:53:03 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 03:53:07 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager_internal.h"
#include "libft.h"

t_env_tab	*__env_table_init__(t_env_tab *table, char **envp)
{
	char	*key;
	char	*value;
	size_t	i;
	size_t	j;

	if (!envp)
		return (NULL);
	hash_table_init(table);
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
