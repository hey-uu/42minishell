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
#include "tree.h"
#include "executor.h"
#include "minishell.h"
#include "parser.h"
#include "env_manager.h"

void	free_double_char_array(char ***array);
char	*ft_str3join(char *s1, char *s2, char *s3);

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

static int	check_given_command_path(char **cmd_path)
{
	struct stat	f_stat;

	stat(*cmd_path, &f_stat);
	if (access(*cmd_path, F_OK) == -1)
		printf("goldsh: No such file or directory\n");
	else if (S_ISDIR(f_stat.st_mode))
		printf("goldsh: is a directory\n");
	else if (access(*cmd_path, X_OK) == -1)
		printf("goldsh: Permission denied\n");
	else
		return (SUCCESS);
	return (FAILURE);
}

static int	check_path_dir_have_cmd(char **cmd_name)
{
	char			**paths;
	char			*found;
	int				i;

	paths = ft_split(env_get("PATH"), ':');
	if (!paths)
	{
		printf("goldsh: No such file or directory\n");
		return (FAILURE);
	}
	found = NULL;
	i = 0;
	while (paths[i])
		if (find_reg_file_in_a_dir(paths[i++], *cmd_name, &found) == SUCCESS)
			break ;
	free_double_char_array(&paths);
	if (found)
	{
		free(*cmd_name);
		*cmd_name = found;
		return (SUCCESS);
	}
	else
		printf("goldsh: command not found\n");
	return (FAILURE);
}

int	access_command(char **cmd)
{
	int			res;

	if (!*cmd)
		exit(0);
	else if (ft_strchr(*cmd, '/'))
		res = check_given_command_path(cmd);
	else
		res = check_path_dir_have_cmd(cmd);
	return (res);
}
