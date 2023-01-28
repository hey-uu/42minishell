/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:55:14 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:17:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_internal_bonus.h"

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
