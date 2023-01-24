/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_internal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:40:41 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/24 23:41:50 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "builtin_internal.h"
#include "env_manager.h"
#include "error.h"
#include "libft.h"

int	cd_check_access(char *dir)
{
	if (access(dir, F_OK) == -1)
	{
		print_error_message(ERROR_NOT_EXIST, BUILTIN_CD, dir);
		return (ACCESS_FAIL);
	}
	if (access(dir, X_OK) == -1)
	{
		print_error_message(ERROR_PERMISSION_DENIED, BUILTIN_CD, dir);
		return (ACCESS_FAIL);
	}
	return (ACCESS_SUCCESS);
}

int	cd_set_pwd_variables(char *oldpwd_dir)
{
	char	*pwd_dir;

	pwd_dir = getcwd(NULL, 0);
	if (!pwd_dir)
	{
		free(oldpwd_dir);
		print_error_message(ERROR_EXECUTE_FAILED, BUILTIN_CD, "getcwd");
		return (BUILTIN_FAIL);
	}
	env_set(ft_strdup(VAR_PWD), pwd_dir);
	env_set(ft_strdup(VAR_OLDPWD), oldpwd_dir);
	return (BUILTIN_SUCCESS);
}

int	cd_directory_argument(char *cur_dir, char *new_dir)
{
	if (cd_check_access(new_dir) == ACCESS_FAIL)
	{
		free(cur_dir);
		free(new_dir);
		return (BUILTIN_FAIL);
	}
	if (chdir(new_dir) == -1)
	{
		free(cur_dir);
		free(new_dir);
		print_error_message(ERROR_EXECUTE_FAILED, BUILTIN_CD, "chdir");
		return (BUILTIN_FAIL);
	}
	free(new_dir);
	return (cd_set_pwd_variables(cur_dir));
}

int	cd_no_argument(char *cur_dir)
{
	char	*new_dir;

	new_dir = env_dup_val(VAR_HOME);
	if (!new_dir)
	{
		free(cur_dir);
		print_error_message(ERROR_ENV_UNSET, BUILTIN_CD, VAR_HOME);
		return (BUILTIN_FAIL);
	}
	else if (new_dir[0] == '\0')
	{
		free(new_dir);
		env_set(ft_strdup(VAR_OLDPWD), cur_dir);
		return (BUILTIN_SUCCESS);
	}
	else
		return (cd_directory_argument(cur_dir, new_dir));
}

int	cd_hyphen_minus(char *cur_dir)
{
	char	*new_dir;

	new_dir = env_dup_val(VAR_OLDPWD);
	if (!new_dir)
	{
		free(cur_dir);
		print_error_message(ERROR_ENV_UNSET, BUILTIN_CD, VAR_OLDPWD);
		return (BUILTIN_FAIL);
	}
	if (cd_directory_argument(cur_dir, new_dir) == BUILTIN_FAIL)
		return (BUILTIN_FAIL);
	builtin_pwd(NULL);
	return (BUILTIN_SUCCESS);
}
