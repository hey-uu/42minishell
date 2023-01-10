/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:22:06 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/11 00:55:36 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "libft.h"
# include "libadt.h"
# include "lexer.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum e_node_type
{
	NODE_NONE = 0,
	NODE_SIMPLE_CMD = 1,
	NODE_SUBSHELL = 2,
	NODE_PIPELINE = 3,
	NODE_AND_IF = 4,
	NODE_OR_IF = 5,
	NODE_REDIR_LIST = 6
};

/*------------- STRUCT DECLARATIONS --------------*/

// name : 실행하고자 하는 command의 이름(절대 경로 포함 필수 x)
// argv : command의 이름과 command의 인자들
typedef struct s_simple_cmd
{
	char	*name;
	t_queue	*argv;
}	t_simple_cmd;

typedef struct s_redir_list
{
	t_queue	*redir_in;
	t_queue	*redir_out;
}	t_redir_list;

typedef struct s_execute_unit
{
	t_simple_cmd	*simple_cmd;
	t_redir_list	*io_list;
}	t_execute_unit;

typedef struct s_tree_node
{
	int					type;
	t_execute_unit		exe_unit;
	struct s_tree_node	*first_child;
	struct s_tree_node	*next_sibling;
}	t_tree_node;

typedef t_tree_node	t_node;

/*-------------- FUNCTION PROTOTYPES -------------*/

t_node			*create_tree_node(void);
void			destroy_tree(t_node *parent);
int				is_redirection(int type);
t_redir_list	*create_redirect_list(void);
void			push_redirection(\
				t_redir_list *io_list, t_token *token, int offset);
void			push_arguments(\
				t_simple_cmd *simple_cmd, t_token *token, int offset);
void			show_tree(t_node *tree, int depth);

#endif
