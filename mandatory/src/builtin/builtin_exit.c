/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:24:02 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 03:11:58 by hyeyukim         ###   ########.fr       */
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

static void	exit_error_handler(int error_number, char ***argv, char *arg)
{
	print_builtin_error_message(error_number, CMD_EXIT, arg);
	free_double_char_array(argv);
	if (error_number == BERR_NOT_NUMBER)
	{
		exit_stat_update(255);
		exit_program();
	}
	else if (error_number == BERR_TOO_MANY_ARGUMENTS)
	{
		exit_stat_update(1);
	}
}

void	builtin_exit(char *argv[])
{
	printf("exit\n");
	if (argv[1] && (!is_numeric_argument(argv[1])))
		exit_error_handler(BERR_NOT_NUMBER, &argv, argv[1]);
	else if (argv[1] && argv[2])
		exit_error_handler(BERR_TOO_MANY_ARGUMENTS, &argv, NULL);
	else
	{
		if (argv[1])
			exit_stat_update(ft_atoi(argv[1]));
		free_double_char_array(&argv);
		exit_program();
	}
}
