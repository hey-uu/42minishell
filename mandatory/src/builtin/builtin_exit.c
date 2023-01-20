/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:24:02 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/21 01:56:51 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin_internal.h"
#include "env_manager.h"
#include "error.h"
#include "libft.h"

int	builtin_exit(char *argv[])
{
	printf("exit\n");
	if (argv[1] && argv[2])
	{
		free_double_char_array(&argv);
		exit_stat_update(1);
		exit_program();
	}
	if (argv[1])
		exit_stat_update(ft_atoi(argv[1]));
	free_double_char_array(&argv);
	exit_program();
}
