/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_manager.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:40:25 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/15 00:22:39 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_MANAGER_H
# define ENV_MANAGER_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "libadt.h"

typedef t_hash_table	t_env_tab;

/*-------------- FUNCTION PROTOTYPES -------------*/

void	initialize_env_table(t_env_tab **table, char **envp);
char	*env_get(t_env_tab *hash_table, char *variable);
void	env_set(t_env_tab *table, char *variable, char *value);
void	env_unset(t_env_tab *table, char *variable);


#endif