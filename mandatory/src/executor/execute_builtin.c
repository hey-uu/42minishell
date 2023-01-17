/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single_builtin.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:15:38 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/18 00:29:51 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "executor.h"
#include "minishell.h"
#include "parser.h"

static void	backup_standard_stream(int fd[2])
{
	fd[IN] = dup(STDIN_FILENO);
	fd[OUT] = dup(STDOUT_FILENO);
	if (fd[IN] < 0 || fd[OUT] < 0)
		exit_by_error("dup2 failed");
}

static void	restore_standard_stream(int fd[2])
{
	int	res[2];

	res[0] = dup2(fd[IN], STDIN_FILENO);
	res[1] = dup2(fd[OUT], STDOUT_FILENO);
	if (res[0] < 0 || res[1] < 0)
		exit_by_error("dup2 failed");
}

int	get_builtin_cmd_idx(char *cmd_name)
{
	const char	*builtin[6] = {"echo", "cd", "pwd", "export", "env", "exit"};
	int			i;

	if (!cmd_name)
		return (FAILURE);
	i = 0;
	while (i < 6)
	{
		if (strcmp(builtin[i], cmd_name) == 0)
			return (i);
		i++;
	}
	return (FAILURE);
}

int	execute_builtin(t_execute_unit *exe_unit, char **envp)
{
	const t_builtin	cmd_arr[6] = {
		builtin_echo, builtin_cd, builtin_pwd, \
		builtin_export, builtin_env, builtin_exit	
	};
	const int		cmd_idx = get_builtin_cmd_idx(exe_unit->cmd_name);

	cmd_arr[cmd_idx](exe_unit->cmd_argv->strarr, envp);
	return (EXIT_SUCCESS);
}

int	execute_single_builtin(t_execute_unit *exe_unit, char **envp)
{
	int	ori_fd[2];

	backup_standard_stream(ori_fd);
	set_standard_stream(NULL, exe_unit->redir_list, 0);
	execute_builtin(exe_unit, envp);
	restore_standard_stream(ori_fd);
	return (EXIT_SUCCESS);
}
