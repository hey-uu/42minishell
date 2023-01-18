/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:43:40 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 22:39:49 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "s_expansion.h"
# include "tree.h"

/*-------------- FUNCTION PROTOTYPES -------------*/

t_expansion	*expand_word(char *word);
void		destroy_expansion(t_expansion *set);
char		**words_to_strings(t_expansion *set);
char		*split_variable(char *word, int *idx, int *question_mark);
int			do_expansion(t_execute_unit *exe_unit);

#endif