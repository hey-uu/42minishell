/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:14:55 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/09 08:02:12 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*--------------- STANDARD HEADERS ---------------*/

# include <stdio.h>

/*-------------- USER DEFINED HEADERS ------------*/

// # include "vector.h"
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
	NODE_SIMPLE_COMMAND = 1,
	NODE_SUBSHELL = 2,
	NODE_PIPELINE = 3,
	NODE_AND_IF = 4,
	NODE_OR_IF = 5
}	t_node_type;

/**
 * @brief Parsor
 * 
 */
typedef struct s_simple_command
{
	char	*cmd_name;
	t_queue	*argv;
	t_queue	*redir_in;
	t_queue	*redir_out;
}	t_simple_command;

typedef struct s_subshell
{
	int	check;
}	t_subshell;

typedef union u_command
{
	t_simple_command	*simple;
	t_subshell			*subshell;
}	t_command;

typedef struct s_tree
{
	t_node_type			type;
	t_command			content;
	struct s_tree		*first_child;
	struct s_tree		*next_sibling;
}	t_tree;

enum e_syntax_error
{
	NONE = 0,
	
};
typedef enum e_syntax_error t_stx_err;

typedef struct s_goldsh
{
	char		**envp;
	t_token		*token;
	t_tree		*tree;
	t_stx_err	syntax_error;
}	t_goldsh;

t_goldsh	g_goldsh;

/*-------------- FUNCTION PROTOTYPES -------------*/

t_token	*lexer(char *input);
t_tree	*parser(t_token *tokens);
void	destroy_parse_tree(t_tree *node);

#endif