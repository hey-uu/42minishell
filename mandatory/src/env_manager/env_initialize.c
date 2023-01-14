/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:09:45 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/14 23:52:09 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env_manager.h"

static char	*ft_strndup(char *str, int n)
{
	char	*new;
	int		i;

	new = ft_malloc(sizeof(char) * n);
	i = 0;
	while (i < (n - 1) && str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

void	initialize_env_table(t_env_tab **table, char **envp)
{
	int		i;
	int		j;
	char	*key;
	char	*value;

	*table = hash_table_create();
	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		key = ft_strndup(envp[i], ++j);
		value = ft_strdup(&envp[i][j]);
		hash_table_insert(*table, key, value);
		i++;
	}
}
