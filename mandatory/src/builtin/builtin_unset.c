/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 02:06:33 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 09:53:20 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "builtin_internal.h"
#include "env_manager.h"
#include "error.h"
#include "libft.h"

int	is_valid_variable_name(char *name)
{
	int	i;

	i = 0;
	while (name[i])
	{
		if (!is_valid_variable_name_character(name[i], i))
			return (0);
		i++;
	}
	return (1);
}

void	builtin_unset(char *argv[])
{
	int	i;
	int	res;

	i = 1;
	res = BUILTIN_SUCCESS;
	while (argv[i])
	{
		if (is_valid_variable_name(argv[i]))
			env_unset(argv[i]);
		else
		{
			handle_builtin_error(\
			BERR_INVALID_IDENTIFIER, CMD_UNSET, argv[i], 1);
			res = BUILTIN_FAIL;
		}
		free(argv[i]);
		i++;
	}
	free(argv);
	if (res == BUILTIN_SUCCESS)
		exit_stat_update(0);
}
