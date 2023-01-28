/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_dir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:43:24 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 07:44:49 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

DIR	*w_opendir(const char *filename)
{
	DIR	*res;

	res = opendir(filename);
	if (res == NULL)
	{
		perror("goldsh: opendir");
		exit(2);
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
