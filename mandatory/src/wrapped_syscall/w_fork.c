/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:07:17 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 16:09:16 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager.h"
#include "error.h"
#include <unistd.h>

int	w_fork(void)
{
	int	pid;

	pid = fork();
	if (pid < 0)
	{
		handle_execute_error(ERR_EXE_SYSCALL_FAILED, "fork", NULL);
		exit_program();
	}
	return (pid);
}
