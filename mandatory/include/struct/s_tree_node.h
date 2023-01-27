/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_tree_node.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:56:54 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 03:11:46 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_TREE_NODE_H
# define S_TREE_NODE_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "libadt.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum e_node_type
{
	NODE_NONE,
	NODE_SIMPLE_CMD,
	NODE_SUBSHELL,
	NODE_PIPELINE,
	NODE_AND_IF,
	NODE_OR_IF
};

/*------------------ TYPE DEFINE -----------------*/

typedef t_intstr	t_redir;

/*------------- STRUCT DECLARATIONS --------------*/

typedef struct s_execute_unit
{
	char				*cmd_name;
	char				**cmd_argv;
	t_redir				*redir_list;
	t_queue				*q_cmd_argv;
	t_queue				*q_redir_list;
}	t_execute_unit;

typedef struct s_tree_node
{
	int					type;
	t_execute_unit		*exe_unit;
	struct s_tree_node	**root;
	struct s_tree_node	*first_child;
	struct s_tree_node	*next_sibling;
}	t_tree_node;

typedef t_tree_node	t_node;

#endif