/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_push_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:47:57 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:17:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion_internal_bonus.h"

void	push_elem_to_word(t_word *word, char *str, int len, int type)
{
	if (word->elem_cnt == word->alloc_size)
		grow_word_element_array(word);
	word->elem_arr[word->elem_cnt].data = str;
	word->elem_arr[word->elem_cnt].len = len;
	word->elem_arr[word->elem_cnt].type = type;
	word->elem_cnt++;
}

void	push_elem_to_cur_word(t_words *words, char *str, int len, int type)
{
	t_word	*word;

	word = get_cur_word(words);
	push_elem_to_word(word, str, len, type);
}
