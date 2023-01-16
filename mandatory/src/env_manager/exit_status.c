/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:00:36 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 13:08:51 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager.h"

int	exit_status_manager(int option, int new_status)
{
	static int	exit_status;

	if (option == UPDATE_EXIT_STATUS)
	{
		exit_status = new_status;
	}
	return (exit_status);
}
