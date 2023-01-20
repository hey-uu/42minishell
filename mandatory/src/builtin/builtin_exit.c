/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:24:02 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/21 03:11:23 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin_internal.h"
#include "env_manager.h"
#include "error.h"
#include "libft.h"

static int	__is_numeric_argument__(char *argument)
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

static int	__exit_error_handler__(int error_number, char ***argv, char *arg)
{
	print_builtin_error_message(error_number, BUILTIN_EXIT, arg);
	free_double_char_array(argv);
	exit_stat_update(2);
	exit_program();
	return (BUILTIN_FAIL);
}


int	builtin_exit(char *argv[])
{
	printf("exit\n");
	if (argv[1] && (!__is_numeric_argument__(argv[1])))
	{
		return (__exit_error_handler__(ERROR_NOT_NUMBER, &argv, argv[1]));
	}
	if (argv[1] && argv[2])
	{
		return (__exit_error_handler__(ERROR_TOO_MANY_ARGUMENTS, &argv, NULL));
	}
	if (argv[1])
	{
		exit_stat_update(ft_atoi(argv[1]));
	}
	free_double_char_array(&argv);
	exit_program();
	return (BUILTIN_SUCCESS);
}
