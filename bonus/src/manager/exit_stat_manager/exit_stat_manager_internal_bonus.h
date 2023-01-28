/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_stat_manager_internal_bonus.h                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:08:58 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:17:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_STAT_MANAGER_INTERNAL_BONUS_H
# define EXIT_STAT_MANAGER_INTERNAL_BONUS_H

/*--------------- STANDARD HEADERS ---------------*/

# include <stddef.h>

/*-------------- USER DEFINED HEADERS ------------*/

# include "s_env_table_bonus.h"
# include "str_utils_bonus.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum	e_exit_status_manager
{
	EXIT_STAT_GET,
	EXIT_STAT_UPDATE,
	EXIT_MODE_UPDATE,
	EXIT_PROGRAM
};

/*-------------- FUNCTION PROTOTYPES -------------*/

int		exit_stat_manager(int option, unsigned long new_stat);

#endif
