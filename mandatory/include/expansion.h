/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 23:59:05 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/24 17:43:35 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "s_expansion.h"
# include "tree.h"

/*-------------- FUNCTION PROTOTYPES -------------*/

void	do_expansion(t_execute_unit *exe_unit);
char	*split_variable(char *str, int *idx, int *qmark);

#endif