/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:15:38 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/27 19:35:23 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor_internal.h"
#include "wrapped_syscall.h"

void	do_expansion(t_execute_unit *exe_unit);

static void	backup_standard_stream(int fd[2])
{
	fd[IN] = w_dup(STDIN_FILENO);
	fd[OUT] = w_dup(STDOUT_FILENO);
}

static void	restore_standard_stream(int fd[2])
{
	int	res[2];

	res[0] = w_dup2(fd[IN], STDIN_FILENO);
	close(fd[IN]);
	res[1] = w_dup2(fd[OUT], STDOUT_FILENO);
	close(fd[OUT]);
}

int	get_builtin_cmd_idx(char *cmd_name)
{
	const char	*builtin[7] = {"echo", "cd", "pwd", "export", \
								"env", "exit", "unset"};
	int			i;

	if (!cmd_name)
		return (-1);
	i = 0;
	while (i < 7)
	{
		if (ft_strncmp(builtin[i], cmd_name, ft_strlen(cmd_name) + 1) == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	execute_builtin(t_execute_unit *exe_unit)
{
	const t_builtin	cmd_arr[7] = {
		builtin_echo, builtin_cd, builtin_pwd, \
		builtin_export, builtin_env, builtin_exit, builtin_unset	
	};
	const int		cmd_idx = get_builtin_cmd_idx(exe_unit->cmd_name);

	cmd_arr[cmd_idx](exe_unit->cmd_argv);
}

int	execute_single_builtin(t_execute_unit *exe_unit)
{
	int	ori_fd[2];

	do_expansion(exe_unit);
	backup_standard_stream(ori_fd);
	do_redirecting(exe_unit->redir_list);
	execute_builtin(exe_unit);
	restore_standard_stream(ori_fd);
	return (SUCCESS);
}
