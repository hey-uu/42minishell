/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:53:38 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 08:16:27 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_MANAGER_INTERNAL_H
# define ENV_MANAGER_INTERNAL_H

/*--------------- STANDARD HEADERS ---------------*/

# include <stddef.h>

/*-------------- USER DEFINED HEADERS ------------*/

# include "s_env_table.h"
# include "s_tree_node.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum	e_heredoc_manager
{
	HEREDOC_INIT,
	HEREDOC_STAT_GET,
	HEREDOC_STAT_UPDATE,
	HEREDOC_GET_PARSE_TREE
};

enum	e_exit_status_manager
{
	EXIT_STAT_GET,
	EXIT_STAT_UPDATE,
	EXIT_MODE_UPDATE,
	EXIT_PROGRAM
};

enum	e_env_manager
{
	ENV_INIT,
	ENV_GET,
	ENV_SET,
	ENV_UNSET,
	ENV_GET_DEFINED_VAR_LIST,
	ENV_GET_MARKED_VAR_LIST
};

/*-------------- FUNCTION PROTOTYPES -------------*/

// env_manager
void		*env_manager(int option, char *envp[], char *variable, char *value);
t_env_tab	*__env_table_init__(t_env_tab *table, char **envp);
t_env_tab	*__env_set__(t_env_tab *table, char *variable, char *value);
t_env_tab	*__env_unset__(t_env_tab *table, char *variable);
char		*__env_get__(t_env_tab *table, char *variable);
char		**__env_get_marked_variable_list__(t_env_tab *tab);
char		**__env_get_defined_variable_list__(t_env_tab *tab);

// exit_stat_manager
int			exit_stat_update(int new_stat);
int			exit_stat_manager(int option, unsigned long new_stat);

// heredoc_manager
int			heredoc_manager(\
			int option, int new_stat, t_node *root, t_node **root_ptr);

// string utils
char		*ft_strndup(char *str, int n);

#endif
