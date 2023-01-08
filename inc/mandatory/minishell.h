/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:14:55 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/06 13:49:03 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "vector.h"

// subshell 실행(brace)은 지금 구현할 건 아니지만 까먹을까봐 일단 적어두기만 함
typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_LPAREN,
	TOKEN_RPAREN,
	TOKEN_AND_IF,
	TOKEN_OR_IF,
	TOKEN_PIPE,
	TOKEN_RDIR_IN,
	TOKEN_RDIR_OUT,
	TOKEN_HEREDOC,
	TOKEN_APPEND
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*content;
	int				content_len;
	int				expansion_mask; // 와일드카드, 달러 여부 체크하여 마스크로 기록
}	t_token;

typedef enum e_node_type
{
	NODE_COMMAND = 0,
	NODE_SUBSHELL = 1,
	NODE_PIPE = 2,
	NODE_AND_IF = 3,
	NODE_OR_IF= 4,
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