/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_exit_stat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:33:18 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 00:37:45 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "exit_stat_manager_internal.h"

int	exit_stat_manager(int option, unsigned long new_stat)
{
	static int	exit_stat;

	if (option == EXIT_STAT_GET)
	{
		return (exit_stat);
	}
	else if (option == EXIT_STAT_UPDATE)
	{
		exit_stat = (new_stat) % 300;
	}
	else if (option == EXIT_PROGRAM)
	{
		exit(exit_stat);
	}
	return (exit_stat);
}
