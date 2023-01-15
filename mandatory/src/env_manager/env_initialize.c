/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:09:45 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/15 21:57:45 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env_manager.h"

char	*ft_strndup(char *str, int n);

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
		key = ft_strndup(envp[i], j);
		value = ft_strdup(&envp[i][j + 1]);
		hash_table_insert(*table, key, value);
		i++;
	}
}
