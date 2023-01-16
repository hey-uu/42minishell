/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:00:36 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 23:35:01 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_env_table.h"

int	__return_exit_stat__(int exit_stat)
{
	return (exit_stat);
}

int	__update_exit_stat__(int *exit_stat, int new_stat)
{
	*exit_stat = new_stat;
	return (new_stat);
}

int	exit_stat_manager(int option, int new_stat)
{
	static int	exit_stat;

	if (option == EXIT_STAT_GET)
		return (__return_exit_stat__(exit_stat));
	else if (option == EXIT_STAT_UPDATE)
		return (__update_exit_stat__(&exit_stat, new_stat));
	return (0);
}
