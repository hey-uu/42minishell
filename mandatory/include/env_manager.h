/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:40:25 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/26 19:57:16 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_MANAGER_H
# define ENV_MANAGER_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "s_env_table.h"
# include "s_tree_node.h"
/*-------------- FUNCTION PROTOTYPES -------------*/

// exit status manager
int			exit_stat_get(void);
char		*exit_stat_get_dup_str(void);
char		*exit_stat_get_str(void);
int			exit_stat_update(int new_stat);
void		exit_program(void);

// environment variable table
t_env_tab	*init_env_table(char **envp);
void		*env_set(char *variable, char *value);
void		*env_unset(char *variable);
char		*env_get(char *variable);
char		*env_dup_val(char *variable);
char		**env_get_defined_variable_list(void);
char		**env_get_marked_variable_list(void);

// heredoc status manager
void		heredoc_init(t_node *root);
int			heredoc_stat_get(void);
void		heredoc_interupted(char *cur_heredoc_file);

#endif