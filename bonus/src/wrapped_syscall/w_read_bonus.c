/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_read.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:41:52 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 22:44:26 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

ssize_t	w_read(int fildes, void *buf, size_t nbyte)
{
	ssize_t	res;

	res = read(fildes, buf, nbyte);
	if (res == -1)
	{
		perror("goldsh: read");
		exit(2);
	}
	return (res);
}
