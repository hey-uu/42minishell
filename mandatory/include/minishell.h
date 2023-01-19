/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:48:27 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/19 13:54:19 by yeonhkim         ###   ########.fr       */
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
# include "s_token.h"
# include "s_tree_node.h"
# include "error.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum e_result_status
{
	FAILURE = -1,
	SUCCESS = 0
};

/*------------- STRUCT DECLARATIONS --------------*/

typedef struct s_goldsh
{
	char	**envp;
	t_token	*token;
	t_node	*node;
	int		syntax_error;
}	t_goldsh;

t_goldsh	g_goldsh;

/*-------------- FUNCTION PROTOTYPES -------------*/

void	lexer(char *input, t_token **token_list, int *errcode, \
									t_token *syntax_error_near_token);
void	parser(t_token *tokens, t_node **parse_tree, int *errcode, \
									t_token *syntax_error_near_token);
int	do_expansion(t_execute_unit *exe_unit);
void	executor(t_node *parse_tree, int *errcode);

void	destroy_token_list(t_token *token_list);
void	destroy_tree(t_node *node);
int		parse_list(t_node **root, t_token *tokens, int *offset);
char	*process_heredoc(char *word);
void	exit_by_error(char *msg);

#endif
