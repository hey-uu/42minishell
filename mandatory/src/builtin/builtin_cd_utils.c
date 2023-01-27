/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:40:41 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 03:33:24 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_internal.h"

void	builtin_pwd(char *argv[]);

int	cd_check_access(char *dir)
{
	if (access(dir, F_OK) == -1)
	{
		handle_builtin_error(ERR_B_NO_SUCH_FILE_OR_DIR, CMD_CD, dir);
		return (FAILURE);
	}
	if (access(dir, X_OK) == -1)
	{
		handle_builtin_error(ERR_B_PERMISSION_DENIED, CMD_CD, dir);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	cd_set_pwd_variables(char *oldpwd_dir)
{
	char	*pwd_dir;

	pwd_dir = getcwd(NULL, 0);
	if (!pwd_dir)
	{
		free(oldpwd_dir);
		handle_builtin_error(ERR_B_EXECUTE_FAILED, CMD_CD, "getcwd");
		return (FAILURE);
	}
	env_set(ft_strdup(VAR_PWD), pwd_dir);
	env_set(ft_strdup(VAR_OLDPWD), oldpwd_dir);
	return (SUCCESS);
}

int	cd_directory_argument(char *cur_dir, char *new_dir)
{
	if (cd_check_access(new_dir) == FAILURE)
	{
		free(cur_dir);
		free(new_dir);
		return (FAILURE);
	}
	if (chdir(new_dir) == -1)
	{
		free(cur_dir);
		free(new_dir);
		handle_builtin_error(ERR_B_EXECUTE_FAILED, CMD_CD, "chdir");
		return (FAILURE);
	}
	free(new_dir);
	if (cd_set_pwd_variables(cur_dir) == FAILURE)
		return (FAILURE);
	exit_stat_update(0);
	return (SUCCESS);
}

void	cd_no_argument(char *cur_dir)
{
	char	*new_dir;

	new_dir = env_dup_val(VAR_HOME);
	if (!new_dir)
	{
		free(cur_dir);
		handle_builtin_error(ERR_B_NOT_SET, CMD_CD, VAR_HOME);
		return ;
	}
	else if (new_dir[0] == '\0')
	{
		free(new_dir);
		env_set(ft_strdup(VAR_OLDPWD), cur_dir);
		return ;
	}
	else if (cd_directory_argument(cur_dir, new_dir) == FAILURE)
		return ;
	exit_stat_update(0);
}

void	cd_hyphen_minus(char *cur_dir)
{
	char	*new_dir;

	new_dir = env_dup_val(VAR_OLDPWD);
	if (!new_dir)
	{
		free(cur_dir);
		handle_builtin_error(ERR_B_NOT_SET, CMD_CD, VAR_OLDPWD);
		return ;
	}
	if (cd_directory_argument(cur_dir, new_dir) == FAILURE)
		return ;
	exit_stat_update(0);
	builtin_pwd(NULL);
}
