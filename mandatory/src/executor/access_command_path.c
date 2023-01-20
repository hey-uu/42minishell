/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_command_path.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 03:45:26 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/21 06:18:17 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "executor.h"
#include "minishell.h"
#include "parser.h"
#include "env_manager.h"

static void	free_paths(char *paths[])
{
	int	i;

	i = 0;
	while (paths[i])
		free(paths[i++]);
}

static char	*find_env_path_address(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + ft_strlen("PATH="));
		i++;
	}
	return (NULL);
}

static char	**get_paths(void)
{
	const char	**envp = (const char **)env_get_variable_list();
	char		**paths;
	char		*env_path_str;

	env_path_str = find_env_path_address((char **)envp);
	if (!env_path_str)
		printf("There's not PATH enviroment variable\n");
	paths = ft_split(env_path_str, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

static int	find_accessible_command_path(char **cmd_path, char *paths[])
{
	char	*checking;
	int		i;

	i = 0;
	while (paths[i])
	{
		checking = ft_strjoin(paths[i], *cmd_path);
		if (access(checking, X_OK) == 0)
		{
			free(*cmd_path);
			*cmd_path = checking;
			return (SUCCESS);
		}
		free(checking);
		i++;
	}
	return (FAILURE);
}

int	access_command_path(char **cmd_name)
{
	char		**paths;
	char		*cmd_path;
	int			res;

	if (access(*cmd_name, X_OK) == 0)
		return (SUCCESS);
	paths = get_paths();
	if (!paths)
		exit(1);
	cmd_path = ft_strjoin("/", *cmd_name);
	if (find_accessible_command_path(&cmd_path, paths) == SUCCESS)
	{
		free(*cmd_name);
		*cmd_name = cmd_path;
		res = SUCCESS;
	}
	else
		res = FAILURE;
	free_paths(paths);
	return (res);
}
