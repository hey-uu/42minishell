/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_wait.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:14:47 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 17:47:03 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <sys/wait.h>
#include "error.h"
#include "env_manager.h"

int	w_wait(int *stat_loc)
{
	int	res;

	res = wait(stat_loc);
	if (res == -1)
	{
		handle_execute_error(ERR_EXE_SYSCALL_FAILED, "wait", NULL);
		exit_program();
	}
	return (res);
}
