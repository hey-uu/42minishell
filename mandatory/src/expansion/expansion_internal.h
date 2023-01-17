/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:47:19 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/17 15:53:29 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_INTERNAL_H
# define EXPANSION_INTERNAL_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "t_expansion.h"

/*-------------- FUNCTION PROTOTYPES -------------*/

/*** expansion utils ***/
// allocation
t_expansion	*create_expansion_set(char *origin);
t_word		*add_new_word_node_back(t_expansion *set);
void		dup_data_to_word(t_word *node, char *word);
void		concat_node_ndata(t_word *node, char *data, int len);
// expand variable
int			expand_quoted_variable(t_expansion *set, char *word);
int			expand_unquoted_variable(t_expansion *set, char *word);
// destroy
void		destroy_words(t_word *word);
// field_split
void		field_split(t_expansion *set, char *value);

/*** string utils ***/
char		*ft_strndup(char *str, int n);
void		free_double_char_array(char ***array);

#endif