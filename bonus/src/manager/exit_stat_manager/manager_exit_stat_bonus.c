/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_exit_stat_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:33:18 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:17:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "exit_stat_manager_internal_bonus.h"

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
