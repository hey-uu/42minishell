/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:38:43 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 18:40:28 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_internal.h"

void	builtin_pwd(char *argv[])
{
	char	*cur_dir;

	(void)argv;
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
