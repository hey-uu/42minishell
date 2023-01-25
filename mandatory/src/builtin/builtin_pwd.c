/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:38:43 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 09:44:39 by hyeyukim         ###   ########.fr       */
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

	free_double_char_array(&argv);
	cur_dir = getcwd(NULL, 0);
	if (!cur_dir)
	{
		handle_builtin_error(ERROR_EXECUTE_FAILED, CMD_PWD, "getcwd", 1);
		return ;
	}
	if (printf("%s\n", cur_dir) < 0)
	{
		handle_builtin_error(ERROR_EXECUTE_FAILED, CMD_PWD, "printf", 1);
		free(cur_dir);
		return ;
	}
	free(cur_dir);
	exit_stat_update(0);
	return ;
}
