/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single_builtin.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:15:38 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/17 19:14:53 by yeonhkim         ###   ########.fr       */
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
}

static void	restore_standard_stream(int fd[2])
{
	fd[IN] = dup(STDIN_FILENO);
	fd[OUT] = dup(STDOUT_FILENO);
}

// strcmp 구현하여 libft에 넣어야 함
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

int	execute_single_builtin(t_execute_unit *exe_unit, char **envp)
{
	const t_builtin	cmd_arr[6] = {
		builtin_echo, builtin_cd, builtin_pwd, \
		builtin_export, builtin_env, builtin_exit	
		};
	const int		cmd_idx = get_builtin_cmd_idx(exe_unit->cmd_name);
	int				ori_fd[2];

	backup_standard_stream(ori_fd);
	set_standard_stream(NULL, exe_unit->redir_list, 0);
	cmd_arr[cmd_idx](exe_unit->cmd_argv->strarr, envp);
	restore_standard_stream(ori_fd);
	return (EXIT_SUCCESS);
}