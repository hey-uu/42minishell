/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:53:38 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 10:26:19 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_MANAGER_INTERNAL_H
# define ENV_MANAGER_INTERNAL_H

/*--------------- STANDARD HEADERS ---------------*/

# include <stddef.h>

/*-------------- USER DEFINED HEADERS ------------*/

# include "s_env_table.h"

/*-------------- FUNCTION PROTOTYPES -------------*/

// env_manager
void		*env_manager(int option, char *envp[], char *variable, char *value);
t_env_tab	*__env_table_initialize__(t_env_tab *table, char **envp);
t_env_tab	*__env_set__(t_env_tab *table, char *variable, char *value);
t_env_tab	*__env_unset__(t_env_tab *table, char *variable);
char		*__env_get__(t_env_tab *table, char *variable);
char		**__env_tab_to_arr__(t_env_tab *tab);

// exit_stat_manager
int			exit_stat_manager(int option, unsigned long new_stat);

// heredoc_manager
int			heredoc_manager(\
			int option, int new_stat, char *new_file_name, int new_fd);


// string utils
char		*ft_strndup(char *str, int n);

#endif
