/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/01/27 20:31:11 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_INTERNAL_H
# define TREE_INTERNAL_H

/*--------------- STANDARD HEADERS ---------------*/

# include <stddef.h>

/*-------------- USER DEFINED HEADERS ------------*/

# include "constants.h"
# include "s_token.h"
# include "s_tree_node.h"

/*-------------- FUNCTION PROTOTYPES -------------*/

// heredoc
char			*process_heredoc(char *word);

// utils
void			free_strs_array(char ***array);

#endif
