/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:08:20 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 20:21:40 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin_internal.h"
#include "env_manager.h"
#include "error.h"
#include "libft.h"

static int	echo_is_n_option(char *argument, int *newline_flag)
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

static int	echo_arguments(char *argument, int is_last_argument)
{
	int	res;

	res = printf("%s", argument);
	if (res == -1)
		return (PRINTF_FAIL);
	if (!is_last_argument)
	{
		res = printf(" ");
		if (res == -1)
			return (PRINTF_FAIL);
	}
	return (PRINTF_SUCCESS);
}

static int	pass_n_option(char *argv[], int *newline_flag)
{
	int	i;

	i = 1;
	*newline_flag = 1;
	while (argv[i] && argv[i][0] == '-' && argv[i][1] == 'n')
	{
		if (!echo_is_n_option(argv[i], newline_flag))
			break ;
		i++;
	}
	return (i);
}

void	builtin_echo(char *argv[])
{
	int	i;
	int	newline_flag;

	i = pass_n_option(argv, &newline_flag);
	while (argv[i])
	{
		if (echo_arguments(argv[i], (argv[i + 1] == NULL)) == PRINTF_FAIL)
		{
			handle_builtin_error(ERR_B_EXECUTE_FAILED, CMD_ECHO, "printf");
			return ;
		}
		i++;
	}
	if (newline_flag == 1 && printf("\n") < 0)
		handle_builtin_error(ERR_B_EXECUTE_FAILED, CMD_ECHO, "printf");
	else
		exit_stat_update(0);
}
