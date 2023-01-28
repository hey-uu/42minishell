/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_manager_internal.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:53:38 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 12:59:35 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_MANAGER_INTERNAL_H
# define HEREDOC_MANAGER_INTERNAL_H

/*--------------- STANDARD HEADERS ---------------*/

# include <stddef.h>

/*-------------- USER DEFINED HEADERS ------------*/

# include "constants.h"
# include "libadt.h"
# include "s_token.h"
# include "s_tree_node.h"
# include "wrapped_syscall.h"
# include "exit_stat_manager.h"

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
