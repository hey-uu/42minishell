/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_expansion.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 22:48:06 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 22:14:12 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_EXPANSION_H
# define S_EXPANSION_H

/*------------ DEFINE MACRO CONSTANTS ------------*/

# define AMBIGUOUS_REDIRECT -1
# define QUOTED_CHAR_EXIST 1
# define QUOTED_CHAR_NONE 0

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
	t_word		*first;
	t_word		*last;
	int			count;
	int			quote_exist;
}	t_expansion;

#endif