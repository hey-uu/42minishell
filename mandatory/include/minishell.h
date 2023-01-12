/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:14:55 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/12 20:02:31 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*--------------- STANDARD HEADERS ---------------*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*-------------- USER DEFINED HEADERS ------------*/

# include "libft.h"
# include "libadt.h"
# include "tree.h"
# include "lexer.h"
# include "parser.h"
# include "executor.h"
# include "error.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum e_token_type
{
	TOKEN_NONE,
	TOKEN_WORD,
	TOKEN_LPAREN,
	TOKEN_RPAREN,
	TOKEN_AND_IF,
	TOKEN_OR_IF,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_IN_HERE,
	TOKEN_REDIR_OUT_APP
};

enum e_syntax_status
{
	SYNTAX_ERROR = 0,
	SYNTAX_OK = 1
};

enum e_success_or_failure
{
	FAILURE = -1,
	SUCCESS = 0
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

typedef struct s_token
{
	int		type;
	char	*str;
}	t_token;

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

typedef struct s_goldsh
{
	char	**envp;
	t_token	*token;
	t_node	*node;
	int		syntax_error;
}	t_goldsh;

t_goldsh	g_goldsh;

/*-------------- FUNCTION PROTOTYPES -------------*/

t_token	*lexer(char *input);
t_node	*parser(t_token *tokens);
void	destroy_tree(t_node *node);
int		parse_list(t_node **root, t_token *tokens, int *offset);

// error
void	print_syntax_error_message(int token_type, char *token_str);

// lexer
t_token	*lexer(char *input);
void	print_token_list(t_token *list);
void	destroy_token_list(t_token *token_list);
t_token	extract_word_token(char **input);
t_token	extract_operator_token(char **input, const int token_type);
int		get_token_type(const char *input);
int		is_blank(const char c);
int		length_of_word(const char *input);
int		length_of_operator(const int token_type);

// parser
int	is_redirection(int type);
int	parse_list(t_node **root, t_token *tokens, int *offset);
int	parse_pipeline(t_node *node, t_token *tokens, int *offset);
int	parse_simple_command(t_node *node, t_token *token, int *offset);
int	parse_subshell(t_node *node, t_token *tokens, int *offset);


// tree
t_node			*create_tree_node(void);
void			destroy_tree(t_node *node);
t_execute_unit	*create_execute_unit(int node_type);
void			push_arguments(t_queue *cmd_argv, t_token *token, int offset);
void			push_redirection(\
				t_queue *redir_list, t_token *token, int offset);
void			show_tree(t_node *tree, int depth);


#endif