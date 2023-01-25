/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:23:59 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 09:33:24 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin_internal.h"
#include "env_manager.h"
#include "error.h"
#include "libft.h"

static void	env_terminate(\
			char ***argv, char ***envp, int errcode, int exit_stat)
{
	if (argv)
		free_double_char_array(argv);
	if (envp)
		free_double_char_array(envp);
	if (!errcode)
		exit_stat_update(exit_stat);
	else if (errcode == BERR_TOO_MANY_ARGUMENTS)
		handle_builtin_error(BERR_TOO_MANY_ARGUMENTS, CMD_ENV, NULL, exit_stat);
	else if (errcode == BERR_EXECUTE_FAILED)
		handle_builtin_error(BERR_EXECUTE_FAILED, CMD_ENV, "printf", exit_stat);
}

void	builtin_env(char *argv[])
{
	char	**envp;
	int		i;

	if (argv[1])
	{
		env_terminate(&argv, NULL, BERR_TOO_MANY_ARGUMENTS, 1);
		return ;
	}
	envp = env_get_defined_variable_list();
	i = 0;
	while (envp[i])
	{
		if (printf("%s\n", envp[i]) < 0)
		{
			env_terminate(&argv, &envp, BERR_EXECUTE_FAILED, 1);
			return ;
		}
		i++;
	}
	env_terminate(&argv, &envp, BERR_NONE, 0);
}
