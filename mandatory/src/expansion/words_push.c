/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:47:57 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 19:42:06 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion_internal.h"

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
