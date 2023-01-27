/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:20:50 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 18:47:07 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_INTERNAL_H
# define PARSER_INTERNAL_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "constants.h"
# include "s_token.h"
# include "s_tree_node.h"
# include "tree.h"
# include "libft.h"
# include <stdlib.h>

/*-------------- FUNCTION PROTOTYPES -------------*/

int	is_redirection(int type);
int	parse_list(t_node *node, t_token *tokens, int *offset);
int	parse_pipeline(t_node *node, t_token *tokens, int *offset);
int	parse_simple_command(t_node *node, t_token *token, int *offset);
int	parse_subshell(t_node *node, t_token *tokens, int *offset);

#endif