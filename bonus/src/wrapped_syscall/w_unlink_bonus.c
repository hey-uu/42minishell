/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_unlink.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:10:02 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/26 23:35:45 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	w_unlink(const char *path)
{
	int	res;

	res = unlink(path);
	if (res == -1)
	{
		perror("goldsh: unlink");
		exit(2);
	}
	return (res);
}
