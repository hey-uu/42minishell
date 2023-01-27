/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/01/27 18:46:39 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "libadt.h"
# include "s_tree_node.h"
# include "s_token.h"

/*-------------- FUNCTION PROTOTYPES -------------*/

t_node			*create_tree_node(t_node **root);
void			destroy_tree(t_node *node);
t_execute_unit	*create_execute_unit(int node_type);
void			push_arguments(t_queue *q_cmd_argv, t_token *token, int offset);
void			push_arguments(t_queue *q_cmd_argv, t_token *token, int offset);
int				push_redirect(\
				t_queue *q_redir_list, t_token *token, int offset);
void			show_tree(t_node *tree, int depth);
char			*process_heredoc(char *word);

#endif
