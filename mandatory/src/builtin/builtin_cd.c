/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:55:14 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/24 23:42:24 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin_internal.h"
#include "env_manager.h"
#include "error.h"
#include "libft.h"

void	builtin_cd(char	*argv[])
{
	char	*cur_dir;
	int		res;

	cur_dir = getcwd(NULL, 0);
	if (!cur_dir)
	{
		free_double_char_array(&argv);
		exit_stat_update(1);
		return ;
	}
	if (!argv[1])
		res = cd_no_argument(cur_dir);
	else if (!ft_strncmp(argv[1], "-", 2))
		res = cd_hyphen_minus(cur_dir);
	else
		res = cd_directory_argument(cur_dir, ft_strdup(argv[1]));
	if (res == BUILTIN_FAIL)
		exit_stat_update(1);
	else
		exit_stat_update(0);
	free_double_char_array(&argv);
}
