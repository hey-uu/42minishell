/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:40:25 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 21:41:57 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_MANAGER_H
# define ENV_MANAGER_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "t_env_table.h"

/*-------------- FUNCTION PROTOTYPES -------------*/

int			exit_status_manager(int option, int new_status);
t_env_tab	*initialize_env_table(char **envp);
void		*env_set(char *variable, char *value);
void		*env_unset(char *variable);
char		*env_get(char *variable);
char		**env_tab_to_arr(void);


#endif