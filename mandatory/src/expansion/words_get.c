/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 07:49:25 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/24 23:07:52 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "expansion_internal.h"
#include "libft.h"

t_word	*get_cur_word(t_words *words)
{
	t_word	*cur_word;

	cur_word = &words->word_arr[words->word_cnt - 1];
	if (!cur_word->alloc_size)
		init_word_element_array(cur_word, 0);
	return (cur_word);
}

t_word	*get_new_word(t_words *words)
{
	t_word	*new_word;

	if (words->word_cnt == words->alloc_size)
		grow_word_array(words);
	new_word = &words->word_arr[words->word_cnt++];
	if (!new_word->alloc_size)
		init_word_element_array(new_word, 0);
	return (new_word);
}
