/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 03:45:26 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/24 21:18:34 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <dirent.h>
#include "executor_internal.h"

static int	find_reg_file_in_a_dir(char *dir_path, char *look_for_name, \
																char **found)
{
	struct dirent	*dent;
	DIR				*dir;

	*found = NULL;
	dir = opendir(dir_path);
	if (!dir)
		return (FAILURE);
	dent = readdir(dir);
	while (dent)
	{
		if (dent->d_type == DT_REG && ft_strncmp(look_for_name, \
								dent->d_name, ft_strlen(dent->d_name) + 1) == 0)
		{
			*found = ft_str3join(dir_path, "/", look_for_name);
			closedir(dir);
			return (SUCCESS);
		}
		dent = readdir(dir);
	}
	closedir(dir);
	return (FAILURE);
}

static int	check_found_command_path(char *cmd_path, char *cmd_name)
{
	if (!cmd_path)
		handle_access_command_error(COMMAND_NOT_FOUND, cmd_name);
	else if (access(cmd_path, X_OK) == -1)
		handle_access_command_error(PERMISSION_DENIED, cmd_path);
	else
		return (SUCCESS);
	return (FAILURE);
}

static int	check_given_command_name(char **cmd_name)
{
	char			**paths;
	char			*found;
	int				i;

	i = 0;
	paths = ft_split(env_get("PATH"), ':');
	if (!paths)
	{
		handle_access_command_error(NO_SUCH_FILE_OR_DIR, *cmd_name);
		return (FAILURE);
	}
	while (paths[i])
		if (find_reg_file_in_a_dir(paths[i++], *cmd_name, &found) == SUCCESS)
			break ;
	free_str_array(&paths);
	if (check_found_command_path(found, *cmd_name) == SUCCESS)
	{
		free(*cmd_name);
		*cmd_name = found;
		return (SUCCESS);
	}
	return (FAILURE);
}

static int	check_given_command_path(char *cmd_path)
{
	struct stat	f_stat;

	stat(cmd_path, &f_stat);
	if (access(cmd_path, F_OK) == -1)
		handle_access_command_error(NO_SUCH_FILE_OR_DIR, cmd_path);
	else if (S_ISDIR(f_stat.st_mode))
		handle_access_command_error(IS_A_DIR, cmd_path);
	else if (access(cmd_path, X_OK) == -1)
		handle_access_command_error(PERMISSION_DENIED, cmd_path);
	else
		return (SUCCESS);
	return (FAILURE);
}

int	access_command(char **cmd)
{
	if (!*cmd)
		exit(0);
	else if (ft_strchr(*cmd, '/'))
		return (check_given_command_path(*cmd));
	else
		return (check_given_command_name(cmd));
}
