/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_dir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:43:24 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/26 22:54:07 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "error_handle.h"
#include "env_manager.h"

DIR	*w_opendir(const char *filename)
{
	DIR	*res;

	res = opendir(filename);
	if (res == NULL)
	{
		handle_execute_error(ERR_EXE_SYSCALL_FAILED, "opendir", NULL);
		exit_program();
	}
	return (res);
}

int	w_closedir(DIR *dirp)
{
	int	res;

	res = closedir(dirp);
	if (res == -1)
	{
		perror("goldsh: closedir");
		exit(2);
	}
	return (res);
}
