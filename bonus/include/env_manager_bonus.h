/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:40:25 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:17:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_MANAGER_BONUS_H
# define ENV_MANAGER_BONUS_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "s_env_table_bonus.h"

/*-------------- FUNCTION PROTOTYPES -------------*/

t_env_tab	*init_env_table(char **envp);
void		*env_set(char *variable, char *value);
void		*env_unset(char *variable);
char		*env_get(char *variable);
char		*env_dup_val(char *variable);
char		**env_get_defined_variable_list(void);
char		**env_get_marked_variable_list(void);

#endif