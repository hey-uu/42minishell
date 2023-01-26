/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_stat_manager_internal.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 00:35:42 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 08:16:27 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_STAT_MANAGER_INTERNAL_H
# define EXIT_STAT_MANAGER_INTERNAL_H

/*--------------- STANDARD HEADERS ---------------*/

# include <stddef.h>

/*-------------- USER DEFINED HEADERS ------------*/

# include "s_env_table.h"
# include "s_tree_node.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum	e_exit_status_manager
{
	EXIT_STAT_GET,
	EXIT_STAT_UPDATE,
	EXIT_MODE_UPDATE,
	EXIT_PROGRAM
};


/*-------------- FUNCTION PROTOTYPES -------------*/

int			exit_stat_manager(int option, unsigned long new_stat);

// heredoc_manager
int			heredoc_manager(\
			int option, int new_stat, t_node *root, t_node **root_ptr);

// string utils
char		*ft_strndup(char *str, int n);

#endif

