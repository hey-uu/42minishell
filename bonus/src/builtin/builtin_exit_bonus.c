/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:24:02 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:17:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_internal_bonus.h"

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

static void	exit_terminate_with_no_error(int exit_stat)
{
	if (exit_stat >= 0)
		exit_stat_update(exit_stat);
	exit_program();
}

static void	exit_terminate_with_error(char *arg, int errcode)
{
	handle_builtin_error(errcode, CMD_EXIT, arg);
	if (errcode == ERR_B_NOT_NUMBER)
		exit_program();
}

void	builtin_exit(char *argv[])
{
	ft_printf("exit\n");
	if (!argv)
		exit_program();
	if (argv[1] && (!is_numeric_argument(argv[1])))
		exit_terminate_with_error(argv[1], ERR_B_NOT_NUMBER);
	else if (argv[1] && argv[2])
		exit_terminate_with_error(NULL, ERR_B_TOO_MANY_ARGUMENTS);
	else if (argv[1])
		exit_terminate_with_no_error(ft_atoi(argv[1]));
	else
		exit_terminate_with_no_error(-1);
}
