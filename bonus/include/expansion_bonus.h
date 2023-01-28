/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:59:05 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:17:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_BONUS_H
# define EXPANSION_BONUS_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "s_expansion_bonus.h"
# include "tree_bonus.h"

/*-------------- FUNCTION PROTOTYPES -------------*/

void	do_expansion(t_execute_unit *exe_unit);
char	*get_variable_name(char *str, int *idx, int *qmark);
void	expand_redir_list(t_queue **q_redir_list, t_intstr **redir_list);

#endif