/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 02:06:33 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 17:46:29 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_internal.h"

static int	is_valid_variable_name(char *name)
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
			handle_builtin_error(ERR_B_INVALID_IDENTIFIER, CMD_UNSET, argv[i]);
			res = BUILTIN_FAIL;
		}
		i++;
	}
	if (res == BUILTIN_SUCCESS)
		exit_stat_update(0);
}
