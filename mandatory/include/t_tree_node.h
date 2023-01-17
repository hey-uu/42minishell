/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tree_node.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:56:54 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/17 17:00:33 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_TREE_NODE_H
# define T_TREE_NODE_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "libadt.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum e_syntax_status
{
	SYNTAX_ERROR = -1,
	SYNTAX_OK = 1
};

enum e_node_type
{
	NODE_NONE,
	NODE_SIMPLE_CMD,
	NODE_SUBSHELL,
	NODE_PIPELINE,
	NODE_AND_IF,
	NODE_OR_IF
};

/*------------- STRUCT DECLARATIONS --------------*/

typedef struct s_execute_unit
{
	char	*cmd_name;
	t_queue	*cmd_argv;
	t_queue	*redir_list;
}	t_execute_unit;

typedef struct s_tree_node
{
	int					type;
	t_execute_unit		*exe_unit;
	struct s_tree_node	*first_child;
	struct s_tree_node	*next_sibling;
}	t_tree_node;

typedef t_tree_node	t_node;

#endif