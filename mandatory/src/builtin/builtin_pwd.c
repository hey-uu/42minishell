/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:38:43 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/26 20:04:02 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin_internal.h"
#include "env_manager.h"
#include "error.h"
#include "libft.h"

void	builtin_pwd(char *argv[])
{
	char	*cur_dir;

	argv = NULL;
	cur_dir = getcwd(NULL, 0);
	if (!cur_dir)
	{
		handle_builtin_error(ERR_B_EXECUTE_FAILED, CMD_PWD, "getcwd");
		return ;
	}
	if (printf("%s\n", cur_dir) < 0)
	{
		handle_builtin_error(ERR_B_EXECUTE_FAILED, CMD_PWD, "printf");
		free(cur_dir);
		return ;
	}
	free(cur_dir);
	exit_stat_update(0);
	return ;
}
