/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_expansion.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:48:06 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/17 16:34:58 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_EXPANSION_H
# define T_EXPANSION_H

/*------------ DEFINE MACRO CONSTANTS ------------*/

# define AMBIGUOUS_REDIRECT -1

enum e_question_mask
{
	VAR_IS_QMARK,
	VAR_IS_NOT_QMARK
};

enum e_expansion_result_status
{
	EXPAND_AMBIGUOUS_REDIRECT_ERROR= -1,
	EXPAND_SUCCESS = 0
};


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
	char		*origin;
	int			origin_len;
	t_word		*first;
	t_word		*last;
	int			count;
}	t_expansion;

#endif