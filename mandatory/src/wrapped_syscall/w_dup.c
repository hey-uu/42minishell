/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_dup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:10:38 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 16:14:38 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error.h"
#include "env_manager.h"

int	w_dup(int filedes)
{
	int	res;

	res = dup(filedes);
	if (res == -1)
	{
		handle_execute_error(ERR_EXE_SYSCALL_FAILED, "dup", NULL);
		exit_program();
	}
	return (res);
}

int	w_dup2(int filedes, int filedes2)
{
	int	res;

	res = dup2(filedes, filedes2);
	if (res == -1)
	{
		handle_execute_error(ERR_EXE_SYSCALL_FAILED, "dup2", NULL);
		exit_program();
	}
	return (res);
}
