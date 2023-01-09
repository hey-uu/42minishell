/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:14:55 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/09 14:49:54 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*--------------- STANDARD HEADERS ---------------*/

# include <stdio.h>

/*-------------- USER DEFINED HEADERS ------------*/

# include "queue.h"
# include "libft.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

# define SYNTAX_ERROR -1
# define QUEUE_INITIAL_SIZE 10

// subshell 실행(parenthesis)은 지금 구현할 건 아니지만 까먹을까봐 일단 적어두기만 함
typedef enum e_token_type
{
	TOKEN_NONE = 0,
	TOKEN_WORD = 1,
	TOKEN_LPAREN = 2,
	TOKEN_RPAREN = 3,
	TOKEN_AND_IF = 4,
	TOKEN_OR_IF = 5,
	TOKEN_PIPE = 6,
	TOKEN_REDIR_IN = 7,
	TOKEN_REDIR_OUT = 8,
	TOKEN_REDIR_IN_HERE = 9,
	TOKEN_REDIR_OUT_APP = 10
}	t_token_type;


/*------------- STRUCT DECLARATIONS --------------*/


/*------------------------------------------------*/
/**
 * @brief Lexer
 * 
 */
typedef struct s_token
{
	t_token_type	type;
	char			*str;
	// int				str_len;
	// int				expansion_mask; 
	// 와일드카드, 달러 여부 체크하여 마스크로 기록
}	t_token;

typedef enum e_node_type
{
	NODE_NONE = 0,
	NODE_SIMPLE_Cmd = 1,
	NODE_SUBSHELL = 2,
	NODE_PIPELINE = 3,
	NODE_AND_IF = 4,
	NODE_OR_IF = 5
	NODE_REDIRECTION_LIST = 6
}	t_node_type;

/**
 * @brief Parsor
 * 
 */

// name : 실행하고자 하는 command의 이름(절대 경로 포함 필수 x)
// argv : command의 이름과 command의 인자들
typedef struct s_simple_cmd
{
	char	*name;
	t_queue	*argv;
	// heredoc 처리는 파싱하면서 그때 그때 처리하는 건 어떠신지...?
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

typedef struct s_node
{
	t_node_type		type;
	t_execute_unit	exe_unit;
	struct s_node	*first_child;
	struct s_node	*next_sibling;
}	t_node;

typedef t_node	t_subshell;

enum e_syntax_error
{
	NONE = 0,
};

typedef struct s_goldsh
{
	char	**envp;
	t_token	*token;
	t_tree	*tree;
	int		syntax_error;
}	t_goldsh;

t_goldsh	g_goldsh;

/*-------------- FUNCTION PROTOTYPES -------------*/

t_token	*lexer(char *input);
t_tree	*parser(t_token *tokens);
void	destroy_parse_tree(t_tree *node);

#endif