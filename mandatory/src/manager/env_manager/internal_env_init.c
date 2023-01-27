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

static void	__initialize_with_envp__(t_env_tab *table, char **envp)
{
	char	*key;
	char	*value;
	size_t	i;
	size_t	j;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		key = ft_strndup(envp[i], j);
		if (envp[i][j] == '=')
			value = ft_strdup(&envp[i][j + 1]);
		else
			value = NULL;
		hash_table_insert(table, key, value);
		i++;
	}
}

static void	__update_shell_level__(t_env_tab *table)
{
	char	*value;
	int		num;

	value = __env_get__(table, "SHLVL");
	if (!value)
		num = 1;
	else
		num = ft_atoi(value) + 1;
	value = ft_itoa(num);
	__env_set__(table, ft_strdup("SHLVL"), value);
}

static void	__update_oldpwd__(t_env_tab *table)
{
	__env_unset__(table, "OLDPWD");
}

t_env_tab	*__env_table_init__(t_env_tab *table, char **envp)
{
	if (!envp)
		return (NULL);
	hash_table_init(table);
	__initialize_with_envp__(table, envp);
	__update_shell_level__(table);
	__update_oldpwd__(table);
	return (table);
}
