/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_fork.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:07:17 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/26 22:54:07 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager.h"
#include "error_handle.h"
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
