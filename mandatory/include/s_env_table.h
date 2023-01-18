/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_env_table.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:01:55 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 10:19:53 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_ENV_TABLE_H
# define S_ENV_TABLE_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "libadt.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum	e_heredoc_stat
{
	HEREDOC_IN_PROCESS,
	HEREDOC_DONE
};

enum	e_heredoc_manager
{
	HEREDOC_STAT_GET,
	HEREDOC_STAT_UPDATE
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
	ENV_TAB_TO_ARR
};

/*------------- STRUCT DECLARATIONS --------------*/

typedef t_hash_table	t_env_tab;

#endif