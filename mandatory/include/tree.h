/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/01/27 20:14:27 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "libadt.h"
# include "s_token.h"
# include "s_tree_node.h"

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
