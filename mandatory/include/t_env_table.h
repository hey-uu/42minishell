/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env_table.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:01:55 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 23:29:46 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_ENV_TABLE_H
# define T_ENV_TABLE_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "libadt.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum	e_exit_status_manager
{
	EXIT_STAT_GET,
	EXIT_STAT_UPDATE,
};

enum	e_env_manager
{
	ENV_INIT,
	ENV_GET,
	ENV_SET,
	ENV_UNSET,
	ENV_TAB_TO_ARR
};

/*------------- STRUCT DECLARATIONS --------------*/

typedef t_hash_table	t_env_tab;

#endif