/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:48:27 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:19:32 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BONUS_H
# define MINISHELL_BONUS_H

/*--------------- STANDARD HEADERS ---------------*/

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

/*-------------- USER DEFINED HEADERS ------------*/

# include "libadt.h"
# include "libftprintf.h"
# include "constants_bonus.h"
# include "s_token_bonus.h"
# include "s_tree_node_bonus.h"
# include "env_manager_bonus.h"
# include "handle_error_bonus.h"
# include "handle_signal_bonus.h"
# include "prompt_bonus.h"
# include "builtin_bonus.h"

/*-------------- FUNCTION PROTOTYPES -------------*/

void	run_commands(char *input);

/* for run commands */
int		lexer(char *input, t_token **token_list);
int		parser(t_token *tokens, t_node **parse_tree);
int		executor(t_node *parse_tree);
void	destroy_token_list(t_token *token_list);
void	destroy_tree(t_node *node);

#endif
