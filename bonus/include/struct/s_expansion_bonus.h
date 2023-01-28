/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_expansion_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:31:23 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:16:32 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_EXPANSION_BONUS_H
# define S_EXPANSION_BONUS_H

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum e_question_mark
{
	VAR_IS_QMARK,
	VAR_IS_NOT_QMARK
};

/*------------------ TYPE DEFINE -----------------*/

typedef char	*t_string;

/*------------- STRUCT DECLARATIONS --------------*/

typedef struct s_word_elem
{
	char			*data;
	int				len;
	int				type;
}	t_word_elem;

typedef struct s_word
{
	t_word_elem	*elem_arr;
	int			elem_cnt;
	int			mask;
	int			alloc_size;
}	t_word;

typedef struct s_words
{
	t_word	*word_arr;
	int		word_cnt;
	int		alloc_size;
}	t_words;

#endif
