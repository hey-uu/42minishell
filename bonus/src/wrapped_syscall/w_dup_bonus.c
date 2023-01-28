/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_dup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:10:38 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/26 23:34:25 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	w_dup(int filedes)
{
	int	res;

	res = dup(filedes);
	if (res == -1)
	{
		perror("goldsh: dup");
		exit(2);
	}
	return (res);
}

int	w_dup2(int filedes, int filedes2)
{
	int	res;

	res = dup2(filedes, filedes2);
	if (res == -1)
	{
		perror("goldsh: dup2");
		exit(2);
	}
	return (res);
}
