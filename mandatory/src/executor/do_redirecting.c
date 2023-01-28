/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_redirecting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:08:41 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/28 19:54:30 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "wrapped_syscall.h"
#include "executor_internal.h"

static int	redirect_input(char *filename, int redir_type)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		handle_execute_error(ERR_EXE_NO_SUCH_FILE_OR_DIR, NULL, filename);
		return (FAILURE);
	}
	if (redir_type == REDIR_HEREDOC)
		unlink(filename);
	w_dup2(fd, STDIN_FILENO);
	close(fd);
	return (SUCCESS);
}

static int	redirect_output(char *filename, int redir_type)
{
	int	fd;

	(void)redir_type;
	if (redir_type == REDIR_APPEND)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		handle_execute_error(ERR_EXE_NO_SUCH_FILE_OR_DIR, NULL, filename);
		return (FAILURE);
	}
	w_dup2(fd, STDOUT_FILENO);
	close(fd);
	return (SUCCESS);
}

static int	process_redirect(int redir_type, char *filename)
{
	const t_redirect	redir_func[] = {
	[REDIR_IN] = redirect_input,
	[REDIR_OUT] = redirect_output,
	[REDIR_APPEND] = redirect_output,
	[REDIR_HEREDOC] = redirect_input,
	};

	if (redir_type == ERR_EXE_AMBIGUOUS_REDIR)
	{
		handle_execute_error(ERR_EXE_AMBIGUOUS_REDIR, NULL, filename);
		return (FAILURE);
	}
	else
		return (redir_func[redir_type](filename, redir_type));
}

int	do_redirecting(t_redir *redir_list)
{
	int	i;

	i = 0;
	while (redir_list[i].num != REDIR_NONE)
	{
		if (process_redirect(redir_list[i].num, redir_list[i].str) == FAILURE)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
