/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:20:50 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/11 00:41:56 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/**
 * @brief Parser
 * 
 */

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum e_syntax_error
{
	SYNTAX_ERROR = 0,
	SYNTAX_NORMAL = 1
};

/*-------------- USER DEFINED HEADERS ------------*/

# include "tree.h"

/*-------------- FUNCTION PROTOTYPES -------------*/

int	parse_list(t_node **root, t_token *tokens, int *offset);
int	parse_pipeline(t_node *parent, t_token *tokens, int *offset);
int	parse_simple_command(t_node *node, t_token *token, int *offset);
int	parse_subshell(t_node *node, t_token *tokens, int *offset);



#endif