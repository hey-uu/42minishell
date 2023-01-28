/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:23:59 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 18:40:28 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_internal.h"

static void	env_terminate(char ***envp, int errcode)
{
	if (envp)
		free_str_array(envp);
	if (!errcode)
		exit_stat_update(0);
	else if (errcode == ERR_B_TOO_MANY_ARGUMENTS)
		handle_builtin_error(ERR_B_TOO_MANY_ARGUMENTS, CMD_ENV, NULL);
	else if (errcode == ERR_B_EXECUTE_FAILED)
		handle_builtin_error(ERR_B_EXECUTE_FAILED, CMD_ENV, "printf");
}

void	builtin_env(char *argv[])
{
	char	**envp;
	int		i;

	if (argv[1])
	{
		env_terminate(NULL, ERR_B_TOO_MANY_ARGUMENTS);
		return ;
	}
	envp = env_get_defined_variable_list();
	i = 0;
	while (envp[i])
	{
		if (printf("%s\n", envp[i]) < 0)
		{
			env_terminate(&envp, ERR_B_EXECUTE_FAILED);
			return ;
		}
		i++;
	}
	env_terminate(&envp, ERR_B_NONE);
}
