/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 00:51:31 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/15 22:14:14 by yona             ###   ########.fr       */
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


typedef int	(*t_builtin)(char **argv, char **envp);

int	executor(t_node *node, char *envp[]);
int	echo(char **argv, char **envp);
int	cd(char **argv, char **envp);
int	pwd(char **argv, char **envp);
int	export(char **argv, char **envp);
int	env(char **argv, char **envp);
int	m_exit(char **argv, char **envp);
int	put_accessible_command_path(char **cmd_name, char *envp[]);

#endif
