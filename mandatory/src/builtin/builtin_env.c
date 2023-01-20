/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:23:59 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/21 01:46:24 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin_internal.h"
#include "env_manager.h"
#include "error.h"
#include "libft.h"

int	builtin_env(char *argv[])
{
	char	**envp;
	int		i;
	
	if (argv[1])
	{
		free_double_char_array(&argv);
		exit_stat_update(1);
		print_builtin_error_message(ERROR_TOO_MANY_ARGUMENTS, BUILTIN_ENV, NULL);
		return (BUILTIN_FAIL);
	}
	envp = env_tab_to_arr();
	i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
	free_double_char_array(&argv);
	free_double_char_array(&envp);
	return (BUILTIN_SUCCESS);
}
