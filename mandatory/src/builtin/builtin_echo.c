/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:08:20 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/20 22:09:51 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin_internal.h"
#include "env_manager.h"
#include "error.h"
#include "libft.h"

static int	__echo_is_n_option__(char *argument, int *newline_flag)
{
	int	i;

	i = 2;
	while (argument[i])
	{
		if (argument[i] != 'n')
			return (0);
		i++;
	}
	*newline_flag = 0;
	return (1);
}

// partial write도 고려해야하나...
static int	__echo_arguments__(char *argument, int is_last_argument)
{
	int	res;

	res = write(1, argument, ft_strlen(argument));
	if (res == -1)
	{
		exit_stat_update(1);
		return (BUILTIN_FAIL);
	}
	if (!is_last_argument)
	{
		res = write(1, " ", 1);
		if (res == -1)
		{
			exit_stat_update(1);
			return (BUILTIN_FAIL);
		}
	}
	return (BUILTIN_SUCCESS);
}

int	builtin_echo(char *argv[])
{
	int	i;
	int	newline_flag;

	i = 1;
	newline_flag = 1;
	while (argv[i] && argv[i][0] == '-' && argv[i][1] == 'n')
	{
		if (!__echo_is_n_option__(argv[i], &newline_flag))
			break ;
		i++;
	}
	while (argv[i])
	{
		if (__echo_arguments__(argv[i], (argv[i + 1] == NULL)) == BUILTIN_FAIL)
		{
			free_double_char_array(&argv);
			return (BUILTIN_FAIL);
		}
		i++;
	}
	if (newline_flag == 1)
		write(1, "\n", 1);
	free_double_char_array(&argv);
	return (BUILTIN_SUCCESS);
}
