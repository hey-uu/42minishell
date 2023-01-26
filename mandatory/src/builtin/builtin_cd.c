/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:55:14 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 07:47:14 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "builtin_internal.h"
#include "env_manager.h"
#include "exit_stat_manager.h"
#include "error_handle.h"
#include "libft.h"

void	builtin_cd(char	*argv[])
{
	char	*cur_dir;

	cur_dir = getcwd(NULL, 0);
	if (!cur_dir)
	{
		handle_builtin_error(ERR_B_EXECUTE_FAILED, CMD_CD, "getcwd");
		return ;
	}
	if (!argv[1])
		cd_no_argument(cur_dir);
	else if (!ft_strncmp(argv[1], "-", 2))
		cd_hyphen_minus(cur_dir);
	else
		cd_directory_argument(cur_dir, ft_strdup(argv[1]));
}
