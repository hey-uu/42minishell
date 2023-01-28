/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_wait.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:14:47 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 22:21:56 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int	w_wait(int *stat_loc)
{
	int	pid;

	pid = wait(stat_loc);
	if (pid == -1)
	{
		perror("goldsh: wait");
		exit(2);
	}
	return (pid);
}
