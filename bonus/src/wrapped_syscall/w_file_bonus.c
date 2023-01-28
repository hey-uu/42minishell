/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_file.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:42:31 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 22:21:23 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	w_open(const char *path, int oflag, int mode)
{
	int	fd;

	if (mode < 0)
		fd = open(path, oflag);
	else
		fd = open(path, oflag, mode);
	if (fd < 0)
	{
		perror("goldsh: open");
		exit(2);
	}
	return (fd);
}

void	w_close(int fildes)
{
	if (close(fildes) == -1)
	{
		perror("goldsh: close");
		exit(2);
	}
}
