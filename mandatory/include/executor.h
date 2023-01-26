/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 00:51:31 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/26 23:41:16 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

/*--------------- STANDARD HEADERS ---------------*/

# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "s_token.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

# define P_READ 0
# define P_WRITE 1
# define IN 0
# define OUT 1

enum e_redirect_type {
	REDIR_NONE = TOKEN_NONE,
	REDIR_IN = TOKEN_REDIR_IN,
	REDIR_IN_HERE = TOKEN_REDIR_IN_HERE,
	REDIR_OUT = TOKEN_REDIR_OUT,
};

typedef struct s_pipeline {
	int	pipe_exist;
	int	child_cnt;
	int	old_pipe_fd[2];
	int	new_pipe_fd[2];
	int	last_child_pid;
	int	exit_status;
}	t_pipeline;

typedef int	(*t_redirect)(char *, int);

/*------------- STRUCT DECLARATIONS --------------*/

typedef void	(*t_builtin)(char **argv);

int	executor(t_node *parse_tree);

void	builtin_echo(char *argv[]);
void	builtin_cd(char *argv[]);
void	builtin_pwd(char *argv[]);
void	builtin_export(char *argv[]);
void	builtin_env(char *argv[]);
void	builtin_exit(char *argv[]);
void	builtin_unset(char *argv[]);

int		access_command(char **cmd_name);

int		execute_list(t_node *node);
int		execute_pipeline(t_node *node);
int		execute_single_builtin(t_execute_unit *exe_unit);
int		execute_subshell(t_node *node, t_pipeline *pl, int nth);
int		execute_simple_command(\
		t_execute_unit *exe_unit, t_pipeline *pl, int nth);
int		get_builtin_cmd_idx(char *cmd_name);

int		do_redirecting(t_redir *redir_list);
void	set_standard_stream(t_pipeline *pl, t_redir *redir_list, int nth);
void	open_new_pipe(int new_pipe_fd[2]);
void	close_pipe_in_parent(\
		int old_pipe_fd[2], int new_pipe_fd[2], int first, int last);
void	execute_builtin(t_execute_unit *exe_unit);

#endif
