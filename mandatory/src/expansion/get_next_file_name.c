/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_file_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:13:43 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 19:11:23 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <sys/types.h>
#include <dirent.h>

char	*get_next_file_name(int is_dot)
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
		if (is_dot)
			return (file_name);
		if (file_name[0] != '.')
			return (file_name);
		file = readdir(dir_ptr);
	}
	closedir(dir_ptr);
	dir_ptr = NULL;
	return (NULL);
}
