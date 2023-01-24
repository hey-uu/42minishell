/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:23:59 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 00:31:39 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin_internal.h"
#include "env_manager.h"
#include "error.h"
#include "libft.h"

static void	env_terminate(char ***argv, char ***envp, int exit_stat)
{
	if (argv)
		free_double_char_array(argv);
	if (envp)
		free_double_char_array(envp);
	exit_stat_update(exit_stat);
}

void	builtin_env(char *argv[])
{
	char	**envp;
	int		i;

	if (argv[1])
	{
		print_builtin_error_message(BERR_TOO_MANY_ARGUMENTS, CMD_ENV, NULL);
		env_terminate(&argv, NULL, 1);
		return ;
	}
	envp = env_get_defined_variable_list();
	i = 0;
	while (envp[i])
	{
		if (printf("%s\n", envp[i]) < 0)
		{
			env_terminate(&argv, &envp, 1);
			return ;
		}
		i++;
	}
	env_terminate(&argv, &envp, 0);
}
