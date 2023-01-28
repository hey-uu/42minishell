/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager_internal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:53:38 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 15:55:26 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_MANAGER_INTERNAL_H
# define ENV_MANAGER_INTERNAL_H

/*--------------- STANDARD HEADERS ---------------*/

# include <stddef.h>

/*-------------- USER DEFINED HEADERS ------------*/

# include "libft.h"
# include "s_env_table.h"
# include "str_utils.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

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

// string utils

#endif
