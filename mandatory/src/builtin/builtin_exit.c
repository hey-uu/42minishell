/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:24:02 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 15:19:29 by hyeyukim         ###   ########.fr       */
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

static void	exit_terminate_with_no_error(char ***argv, int exit_stat)
{
	free_double_char_array(argv);
	if (exit_stat >= 0)
		exit_stat_update(exit_stat);
	exit_program();
}

static void	exit_terminate_with_error(char ***argv, char *arg, int errcode)
{
	handle_builtin_error(errcode, CMD_EXIT, arg);
	free_double_char_array(argv);
	if (errcode == ERR_B_NOT_NUMBER)
		exit_program();
}

void	builtin_exit(char *argv[])
{
	printf("exit\n");
	if (!argv)
		exit_program();
	if (argv[1] && (!is_numeric_argument(argv[1])))
		exit_terminate_with_error(&argv, argv[1], ERR_B_NOT_NUMBER);
	else if (argv[1] && argv[2])
		exit_terminate_with_error(&argv, NULL, ERR_B_TOO_MANY_ARGUMENTS);
	else if (argv[1])
		exit_terminate_with_no_error(&argv, ft_atoi(argv[1]));
	else
		exit_terminate_with_no_error(&argv, -1);
}
