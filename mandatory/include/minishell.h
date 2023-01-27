/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:48:27 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 20:37:24 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*--------------- STANDARD HEADERS ---------------*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

/*-------------- USER DEFINED HEADERS ------------*/

# include "libadt.h"
# include "libprintf.h"
# include "prompt.h"
# include "constants.h"
# include "s_token.h"
# include "s_tree_node.h"
# include "env_manager.h"
# include "handle_error.h"
# include "handle_signal.h"

/*-------------- FUNCTION PROTOTYPES -------------*/

void	run_commands(char *input);
// run commands
int		lexer(char *input, t_token **token_list);
int		parser(t_token *tokens, t_node **parse_tree);
int		executor(t_node *parse_tree);

void	destroy_token_list(t_token *token_list);
void	destroy_tree(t_node *node);

#endif
