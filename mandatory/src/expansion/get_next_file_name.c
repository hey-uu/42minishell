/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_file_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:13:43 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/24 23:11:29 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <sys/types.h>
#include <dirent.h>
#include "libft.h"

char	*get_next_file_name(void)
{
	static DIR				*dir_ptr;
	static struct dirent	*file;
	char					*file_name;

	if (!dir_ptr)
		dir_ptr = opendir(".");
	file = readdir(dir_ptr);
	while (file)
	{
		file_name = file->d_name;
		if (ft_strncmp(file_name, ".", 2) && ft_strncmp(file_name, "..", 3))
			return (file_name);
		file = readdir(dir_ptr);
	}
	closedir(dir_ptr);
	dir_ptr = NULL;
	return (NULL);
}
