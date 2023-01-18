/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 00:51:31 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 12:24:00 by yeonhkim         ###   ########.fr       */
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

int	executor(t_node *node);

int	builtin_echo(char **argv, char **envp);
int	builtin_cd(char **argv, char **envp);
int	builtin_pwd(char **argv, char **envp);
int	builtin_export(char **argv, char **envp);
int	builtin_env(char **argv, char **envp);
int	builtin_exit(char **argv, char **envp);


int	access_command_path(char **cmd_name);

int	execute_pipeline(t_node *node);
int	execute_single_builtin(t_execute_unit *exe_unit);
int	execute_subshell(t_node *node, t_pipeline *pl, int nth);
int	execute_simple_command(t_execute_unit *exe_unit, t_pipeline *pl, int nth);
int	get_builtin_cmd_idx(char *cmd_name);

void	set_standard_stream(t_pipeline *pl, t_queue *redir_list, int nth);
void	open_new_pipe(int new_pipe_fd[2]);
void	close_pipe_in_parent(int old_pipe_fd[2], int new_pipe_fd[2], int first, int last);
int		execute_builtin(t_execute_unit *exe_unit);

#endif
