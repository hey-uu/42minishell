/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:24:02 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 09:54:40 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin_internal.h"
#include "env_manager.h"
#include "error.h"
#include "libft.h"

static int	is_numeric_argument(char *argument)
{
	int	i;

	i = 0;
	while (argument[i])
	{
		if (!ft_isdigit(argument[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	exit_terminate(\
			char ***argv, char *arg, int errcode, int exit_stat)
{
	free_double_char_array(argv);
	if (!errcode && exit_stat >= 0)
		exit_stat_update(exit_stat);
	else if (errcode > 0)
		handle_builtin_error(errcode, CMD_EXIT, arg, exit_stat);
	if (!errcode | (errcode == BERR_NOT_NUMBER))
		exit_program();
}

void	builtin_exit(char *argv[])
{
	printf("exit\n");
	if (argv[1] && (!is_numeric_argument(argv[1])))
		exit_terminate(&argv, argv[1], BERR_NOT_NUMBER, 255);
	else if (argv[1] && argv[2])
		exit_terminate(&argv, NULL, BERR_TOO_MANY_ARGUMENTS, 1);
	else if (argv[1])
		exit_terminate(&argv, NULL, BERR_NONE, ft_atoi(argv[1]));
	else
		exit_terminate(&argv, NULL, BERR_NONE, -1);
}
