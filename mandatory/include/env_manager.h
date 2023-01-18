/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:40:25 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 10:59:16 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_MANAGER_H
# define ENV_MANAGER_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "s_env_table.h"

/*-------------- FUNCTION PROTOTYPES -------------*/

// exit status manager
int			exit_stat_get(void);
char		*exit_stat_get_str(void);
int			exit_stat_update(int new_stat);
void		exit_program(void);

// environment variable table
t_env_tab	*initialize_env_table(char **envp);
void		*env_set(char *variable, char *value);
void		*env_unset(char *variable);
char		*env_get(char *variable);
char		*env_dup_val(char *variable);
char		**env_tab_to_arr(void);

// heredoc status manager
void		heredoc_is_in_process(char *file_name, int fd);
void		heredoc_is_done(void);
int			heredoc_stat_get(void);

#endif