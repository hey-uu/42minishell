/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 00:51:31 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 19:45:59 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_INTERNAL_H
# define EXECUTOR_INTERNAL_H

/*--------------- STANDARD HEADERS ---------------*/

# include <stdlib.h>
# include <unistd.h>

/*-------------- USER DEFINED HEADERS ------------*/

# include "libft.h"
# include "constants.h"
# include "str_utils.h"
# include "handle_error.h"
# include "handle_signal.h"
# include "env_manager.h"
# include "exit_stat_manager.h"
# include "tree.h"
# include "builtin.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum e_pipe {
	P_READ	= 0,
	P_WRITE	= 1
};

enum e_input_output {
	IN,
	OUT
};

enum e_redirect_type {
	REDIR_NONE = TOKEN_NONE,
	REDIR_IN = TOKEN_REDIR_IN,
	REDIR_HEREDOC = TOKEN_REDIR_IN_HERE,
	REDIR_OUT = TOKEN_REDIR_OUT,
	REDIR_APPEND = TOKEN_REDIR_OUT_APP,
};

/*------------------ TYPE DEFINE -----------------*/

typedef int		(*t_redirect)(char *filename, int redir_type);
typedef void	(*t_builtin)(char **argv);

/*------------- STRUCT DECLARATIONS --------------*/

typedef struct s_pipeline {
	int	pipe_exist;
	int	child_cnt;
	int	old_pipe_fd[2];
	int	new_pipe_fd[2];
	int	last_child_pid;
	int	exit_status;
}	t_pipeline;

/*-------------- FUNCTION PROTOTYPES -------------*/

/* execute */
int		execute_list(t_node *node);
int		execute_pipeline(t_node *node);
int		execute_subshell(t_node *node, t_pipeline *pl, int nth);
int		execute_simple_command(t_execute_unit *exe_unit, \
													t_pipeline *pl, int nth);
int		execute_single_builtin(t_execute_unit *exe_unit);
void	execute_builtin(t_execute_unit *exe_unit);

/* input/output stream  */
void	set_standard_stream(t_pipeline *pl, t_redir *redir_list, int nth);
int		do_redirecting(t_redir *redir_list);
void	open_new_pipe(int new_pipe_fd[2]);
void	close_pipe_in_parent(int old_pipe_fd[2], int new_pipe_fd[2], \
														int first, int last);
/* utils for execute */
int		access_command(char **cmd_name);
int		get_builtin_cmd_idx(char *cmd_name);

#endif
