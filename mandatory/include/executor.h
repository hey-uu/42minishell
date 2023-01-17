/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 00:51:31 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/17 17:37:40 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define P_READ	0
#define P_WRITE	1
#define IN		0
#define OUT		1

typedef struct s_pipeline {
	int	pipe_exist;
	int	child_cnt;
	int	old_pipe_fd[2];
	int	new_pipe_fd[2];
	int	last_child_pid;
	int	exit_status;
} t_pipeline;

typedef int	(*t_builtin)(char **argv, char **envp);

int	executor(t_node *node, char *envp[]);

int	builtin_echo(char **argv, char **envp);
int	builtin_cd(char **argv, char **envp);
int	builtin_pwd(char **argv, char **envp);
int	builtin_export(char **argv, char **envp);
int	builtin_env(char **argv, char **envp);
int	builtin_exit(char **argv, char **envp);


int	access_command_path(char **cmd_name, char *envp[]);

int	execute_pipeline(t_node *node, char **envp);
int	execute_single_builtin(t_execute_unit *exe_unit, char **envp);
int	execute_subshell(t_node *node, char **envp, t_pipeline *pl, int nth);
int	execute_simple_command(t_execute_unit *exe_unit, char **envp, t_pipeline *pl, int nth);
int	get_builtin_cmd_idx(char *cmd_name);

void	set_standard_stream(t_pipeline *pl, t_queue *redir_list, int nth);


#endif
