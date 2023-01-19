/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_open_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:53:51 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 23:53:59 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "executor.h"
#include "minishell.h"
#include "parser.h"

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
