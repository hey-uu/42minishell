/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:14:55 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 23:18:35 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*--------------- STANDARD HEADERS ---------------*/

# include <stdio.h>
# include <stdlib.h>

/*-------------- USER DEFINED HEADERS ------------*/

# include "libft.h"
# include "libadt.h"
# include "t_token.h"
# include "t_tree_node.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/


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

t_token	*lexer(char *input);
t_node	*parser(t_token *tokens);
void	destroy_token_list(t_token *token_list);
void	destroy_tree(t_node *node);
int		parse_list(t_node **root, t_token *tokens, int *offset);
char	*process_heredoc(char *word);

#endif
