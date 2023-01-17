/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:55:14 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 00:15:26 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_internal.h"
#include "env_manager.h"
#include "libft.h"

static int	__cd_no_argument__(void)
{
	const char	*home_dir = env_get(VAR_HOME);
	const char	*curr_dir = env_get(VAR_PWD);

	if (!home_dir)
		return (BUILTIN_FAIL);
	if (chdir(home_dir) == -1)
		return (BUILTIN_FAIL);
	if (!env_set(VAR_OLDPWD, curr_dir))
		return (BUILTIN_FAIL);
	if (!env_set(VAR_PWD, home_dir))
		return (BUILTIN_FAIL);
	return (BUILTIN_SUCCESS);
}

static int	__cd_hypen_minus__(void)
{
	const char	*curr_dir = env_get(VAR_PWD);

	if (!env_set(VAR_OLDPWD, curr_dir))
		return (BUILTIN_FAIL);
	if (!)
}

int	builtin_cd(char	*argv[])
{
	if (argv && argv[0] && argv[1] && argv[2])
		printf("cd: too many arguments\n");
	if (!argv[1])
		return (__cd_no_argument__());
	if (!ft_strncmp(argv[1], "-", ft_strlen(argv[1]) + 1))
		return (__cd_hyphen_minus__());
}
