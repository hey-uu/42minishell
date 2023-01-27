/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_open_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:53:51 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 17:53:05 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor_internal.h"

void	open_new_pipe(int new_pipe_fd[2])
{
	pipe(new_pipe_fd);
}

void	close_pipe_in_parent(int old_pipe_fd[2], int new_pipe_fd[2], \
														int first, int last)
{
	if (first)
	{
		close(new_pipe_fd[P_WRITE]);
	}
	else if (last)
	{
		close(old_pipe_fd[P_READ]);
	}
	else
	{
		close(old_pipe_fd[P_READ]);
		close(new_pipe_fd[P_WRITE]);
	}
}
