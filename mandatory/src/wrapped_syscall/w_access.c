/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_access.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:39:52 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 16:42:13 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "error.h"
#include "env_manager.h"

int	w_access(const char *path, int mode)
{
	int	res;

	res = w_access(path, mode);
	if (res == -1)
	{
		handle_execute_error(ERR_EXE_AMBIGUOUS_REDIR, "access", NULL);
		exit_program();
	}
	return (res);
}
