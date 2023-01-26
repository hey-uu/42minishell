/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_write.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:44:12 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 22:44:59 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

ssize_t	w_write(int fildes, const void *buf, size_t nbyte)
{
	ssize_t	res;

	res = write(fildes, buf, nbyte);
	if (res == -1)
	{
		perror("goldsh: write");
		exit(2);
	}
	return (res);
}
