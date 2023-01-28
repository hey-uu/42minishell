/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 09:55:14 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 15:33:54 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_internal.h"

void	builtin_cd(char	*argv[])
{
	char	*cur_dir;

	cur_dir = getcwd(NULL, 0);
	if (!argv[1])
		cd_no_argument(cur_dir);
	else if (!ft_strncmp(argv[1], "-", 2))
		cd_hyphen_minus(cur_dir);
	else
		cd_directory_argument(cur_dir, ft_strdup(argv[1]));
}
