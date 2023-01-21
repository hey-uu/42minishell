/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:38:43 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/21 08:49:01 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin_internal.h"
#include "env_manager.h"
#include "error.h"
#include "libft.h"

int	builtin_pwd(char *argv[])
{
	char	*cur_dir;

	cur_dir = getcwd(NULL, 0);
	free_double_char_array(&argv);
	if (!cur_dir)
	{
		print_error_message(ERROR_EXECUTE_FAILED, BUILTIN_PWD, "getcwd");
		exit_stat_update(1);
		return (BUILTIN_FAIL);
	}
	printf("%s\n", cur_dir);
	free(cur_dir);
	exit_stat_update(0);
	return (BUILTIN_SUCCESS);
}
