/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:14:55 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/06 11:32:39 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "vector.h"

typedef enum e_token_type
{
	TOKENTYPE_WORD = 0,
	TOKENTYPE_BRACE_LEFT = 1,
	TOKENTYPE_BRACE_RIGHT = 2,
	TOKENTYPE_LOGICAL_AND = 3,
	TOKENTYPE_LOGICAL_OR = 4,
	TOKENTYPE_PIPELINE = 5,
	TOKENTYPE_RDIR_IN = 6,
	TOKENTYPE_RDIR_OUT = 7,
	TOKENTYPE_RDIR_HEREDOC = 8,
	TOKENTYPE_RDIR_APPEND = 9
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*content;
	int				content_len;
	int				expansion_mask;
}	t_token;

typedef enum e_node_type
{
	NODE_COMMAND = 0,
	NODE_SUBSHELL = 1,
	NODE_PIPE = 2,
	NODE_LOGICAL_AND = 3,
	NODE_LOGICAL_OR = 4,
}	t_node_type;

typedef struct s_simple_command
{
	char					*absolute_path;
	char					**argument_list;
	t_ivector				expansion_mask_list;
	t_ivector				rdir_in;
	t_ivector				rdir_out;
	struct s_simple_command	*next;
}	t_simple_command;

typedef struct s_abstract_syntax_tree
{
	t_node_type						type;
	t_simple_command				*simple_command;
	char							**envp;
	struct s_abstract_syntax_tree	*left;
	struct s_abstract_syntax_tree	*right;
}	t_abstract_syntax_tree;

typedef struct s_goldsh
{
	t_token					*token;
	t_abstract_syntax_tree	tree;
}	t_goldsh;

#endif