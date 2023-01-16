/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:43:40 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 14:00:44 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "env_manager.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum e_expansion_mask
{
	EXPAND_NONE = 0,
	EXPAND_SPLITTED = (1 << 0),
	EXPAND_WILDCARD = (1 << 1),
	EXPAND_QUOTED = (1 << 2)
};

/*------------- STRUCT DECLARATIONS --------------*/

typedef struct s_word
{
	char			*data;
	int				len;
	int				mask;
	struct s_word	*next;
}	t_word;

typedef struct s_expansion
{
	t_env_tab	*envtab;
	char		*origin;
	int			origin_len;
	t_word		*first;
	t_word		*last;
	int			count;
}	t_expansion;

/*-------------- FUNCTION PROTOTYPES -------------*/

t_expansion	*expand_word(char *word, t_env_tab *envtab);
void		destroy_expansion(t_expansion *set);
char		**words_to_strings(t_expansion *set, int count);

#endif