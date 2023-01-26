/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_env_table.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:01:55 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 23:40:01 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_ENV_TABLE_H
# define S_ENV_TABLE_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "libadt.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum	e_heredoc_stat
{
	HEREDOC_NONE,
	HEREDOC_IN_PROCESS,
	HEREDOC_DONE,
	HEREDOC_INTSIG
};

/*------------- STRUCT DECLARATIONS --------------*/

typedef t_hash_table	t_env_tab;

#endif