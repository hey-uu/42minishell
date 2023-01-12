/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:22:06 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/12 14:01:52 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "minishell.h"

/*-------------- FUNCTION PROTOTYPES -------------*/

t_node			*create_tree_node(void);
void			destroy_tree(t_node *node);
t_execute_unit	*create_execute_unit(int node_type);
void			push_arguments(t_queue *cmd_argv, t_token *token, int offset);
void			push_redirection(\
				t_queue *redir_list, t_token *token, int offset);
void			show_tree(t_node *tree, int depth);

#endif