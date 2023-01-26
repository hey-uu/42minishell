/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_fork.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:07:17 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/26 23:35:02 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	w_fork(void)
{
	int	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("goldsh: fork");
		exit(2);
	}
	return (pid);
}
