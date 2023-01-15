/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:33:19 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/15 22:22:00 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "executor.h"
#include "minishell.h"
#include "parser.h"

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

void	do_redirecting(t_queue *redir_list)
{
	int	fd;
	int	i;

	i = 0;
	while (i < redir_list->used_size)
	{
		if (redir_list->iarr[i] == TOKEN_REDIR_IN)
		{
			fd = open(redir_list->strarr[i], O_RDONLY);
			dup2(fd, STDIN_FILENO);
		}
		else if (redir_list->iarr[i] == TOKEN_REDIR_OUT)
		{
			fd = open(redir_list->strarr[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			dup2(fd, STDOUT_FILENO);
		}
		i++;
	}
}

void	execute_single_builtin(t_execute_unit *exe_unit, char **envp)
{
	const t_builtin	cmd_arr[6] = {echo, cd, pwd, export, env, m_exit};
	const int		cmd_idx = get_builtin_cmd_idx(exe_unit->cmd_name);
	int				ori_fd[2];

	ori_fd[0] = dup(STDIN_FILENO);
	ori_fd[1] = dup(STDOUT_FILENO);
	do_redirecting(exe_unit->redir_list);
	cmd_arr[cmd_idx](exe_unit->cmd_argv->strarr, envp);
	dup2(ori_fd[0], STDIN_FILENO);
	dup2(ori_fd[1], STDOUT_FILENO);
}

void	do_piping(int pipe_fd[2], int last)
{
	static int	ori_out_fd;
	static int	called;

	if (!called && last)
		return ;
	else if (!called)
	{
		ori_out_fd = dup(STDOUT_FILENO);
		pipe(pipe_fd);
		dup2(pipe_fd[P_WRITE], STDOUT_FILENO);
		called = 1;
	}
	else if (last)
	{
		dup2(pipe_fd[P_READ], STDIN_FILENO);
		dup2(ori_out_fd, STDOUT_FILENO);
		called = 0;
	}
	else
	{
		dup2(pipe_fd[P_READ], STDIN_FILENO);
		pipe(pipe_fd);
		dup2(pipe_fd[P_WRITE], STDOUT_FILENO);
	}
}

int	execute_simple_command(t_execute_unit *exe_unit, char **envp, int last)
{
	static int	pipe_fd[2];
	int			pid;

	do_piping(pipe_fd, last);
	do_redirecting(exe_unit->redir_list);
	pid = fork();
	if (pid == 0)
	{
		execve(exe_unit->cmd_name, exe_unit->cmd_argv->strarr, envp);
		return (FAILURE);
	}
	if (last)
		close(pipe_fd[P_READ]);
	close(pipe_fd[P_WRITE]);
	return (SUCCESS);
}

int	executor(t_node *node, char **envp);

int	execute_pipeline(t_node *node, char **envp)
{
	int	pid;

	if (!node->next_sibling && \
			get_builtin_cmd_idx(node->exe_unit->cmd_name) >= 0)
		execute_single_builtin(node->exe_unit, envp);
	while (node)
	{
		if (node->type == NODE_SUBSHELL)
		{
			pid = fork();
			if (pid == 0)
			{
				do_redirecting(node->exe_unit->redir_list);
				executor(node->first_child, envp);
			}
		}
		else
			execute_simple_command(node->exe_unit, envp, (node->next_sibling == NULL));
		node = node->next_sibling;
	}
	return (SUCCESS);
}

int	executor(t_node *node, char *envp[])
{
	if (node->type == NODE_PIPELINE)
		return (execute_pipeline(node->first_child, envp));
	else if (node->type == NODE_AND_IF)
	{
		if (executor(node->first_child, envp) == SUCCESS)
			executor(node->first_child->next_sibling, envp);
	}
	else if (node->type == NODE_OR_IF)
	{
		if (executor(node->first_child, envp) == FAILURE)
			executor(node->first_child->next_sibling, envp);
	}
	return (SUCCESS);
}
