/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:59:09 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/28 12:59:09 by yeonhkim         ###   ########.fr       */
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
