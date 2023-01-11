/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:20:50 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/11 14:55:34 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/**
 * @brief Parser
 * 
 */

/*-------------- USER DEFINED HEADERS ------------*/

# include "tree.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum e_syntax_error
{
	SYNTAX_ERROR = 0,
	SYNTAX_OK = 1
};

/*-------------- FUNCTION PROTOTYPES -------------*/

int	is_redirection(int type);
int	parse_list(t_node **root, t_token *tokens, int *offset);
int	parse_pipeline(t_node *node, t_token *tokens, int *offset);
int	parse_simple_command(t_node *node, t_token *token, int *offset);
int	parse_subshell(t_node *node, t_token *tokens, int *offset);

#endif