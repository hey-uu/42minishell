/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_manager_internal.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:53:38 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 08:16:27 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_MANAGER_INTERNAL_H
# define HEREDOC_MANAGER_INTERNAL_H

/*--------------- STANDARD HEADERS ---------------*/

# include <stddef.h>

/*-------------- USER DEFINED HEADERS ------------*/

# include "s_env_table.h"
# include "s_tree_node.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum	e_heredoc_manager
{
	HEREDOC_INIT,
	HEREDOC_STAT_GET,
	HEREDOC_STAT_UPDATE,
	HEREDOC_GET_PARSE_TREE
};


/*-------------- FUNCTION PROTOTYPES -------------*/

int			heredoc_manager(\
			int option, int new_stat, t_node *root, t_node **root_ptr);

#endif
