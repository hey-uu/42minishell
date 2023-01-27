/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_allocation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:46:04 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 19:41:32 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "expansion_internal.h"

void	init_word_element_array(t_word *word, int initial_size)
{
	if (initial_size <= 0)
		word->alloc_size = INITIAL_WORDELEM_ARR_SIZE;
	else
		word->alloc_size = initial_size;
	word->elem_arr = ft_calloc(word->alloc_size, sizeof(t_word_elem));
	word->mask = EXP_WORD_NONE;
	word->elem_cnt = 0;
}

void	init_words(t_words *words, int initial_size)
{
	if (initial_size <= 0)
		words->alloc_size = INITIAL_WORD_ARR_SIZE;
	else
		words->alloc_size = initial_size;
	words->word_arr = ft_calloc(words->alloc_size, sizeof(t_word));
	words->word_cnt = 1;
}

void	grow_word_array(t_words *words)
{
	t_word	*new;

	words->alloc_size *= 2;
	new = ft_malloc(sizeof(t_word) * words->alloc_size);
	ft_memcpy(new, words->word_arr, sizeof(t_word) * words->word_cnt);
	ft_memset(&new[words->word_cnt], 0, sizeof(t_word) * words->word_cnt);
	free(words->word_arr);
	words->word_arr = new;
}

void	grow_word_element_array(t_word *word)
{
	t_word_elem	*new;

	word->alloc_size *= 2;
	new = ft_malloc(sizeof(t_word_elem) * word->alloc_size);
	ft_memcpy(new, word->elem_arr, sizeof(t_word_elem) * word->elem_cnt);
	ft_memset(&new[word->elem_cnt], 0, sizeof(t_word_elem) * word->elem_cnt);
	free(word->elem_arr);
	word->elem_arr = new;
}

void	free_words(t_words *words)
{
	int	i;

	i = 0;
	while (i < words->word_cnt)
	{	
		free(words->word_arr[i].elem_arr);
		i++;
	}
	free(words->word_arr);
}
