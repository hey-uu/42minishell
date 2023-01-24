/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_array_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 07:49:25 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/24 17:02:07 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "expansion_internal.h"
#include "libft.h"

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

void	init_word_array(t_words *words, int initial_size)
{
	if (initial_size <= 0)
		words->alloc_size = INITIAL_WORD_ARR_SIZE;
	else
		words->alloc_size = initial_size;
	words->word_arr = ft_calloc(words->alloc_size, sizeof(t_word));
	words->word_cnt = 1;
}

void	free_word_array(t_words *words)
{
	int	i;

	while (i < words->word_cnt)
	{	
		free(words->word_arr[i].elem_arr);
		i++;
	}
	free(words->word_arr);
}

void	__grow_word_array__(t_words *words)
{
	t_word	*new;

	words->alloc_size *= 2;
	new = ft_malloc(sizeof(t_word) * words->alloc_size);
	ft_memcpy(new, words->word_arr, sizeof(t_word) * words->word_cnt);
	ft_memset(&new[words->word_cnt], 0, sizeof(t_word) * words->word_cnt);
	free(words->word_arr);
	words->word_arr = new;
}

void	__grow_word_element_array__(t_word *word)
{
	t_word_elem	*new;

	word->alloc_size *= 2;
	new = ft_malloc(sizeof(t_word_elem) * word->alloc_size);
	ft_memcpy(new, word->elem_arr, sizeof(t_word_elem) * word->elem_cnt);
	ft_memset(&new[word->elem_cnt], 0, sizeof(t_word_elem) * word->elem_cnt);
	free(word->elem_arr);
	word->elem_arr = new;
}

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
		__grow_word_array__(words);
	new_word = &words->word_arr[words->word_cnt++];
	if (!new_word->alloc_size)
		init_word_element_array(new_word, 0);
	return (new_word);
}

void	push_elem_to_word(t_word *word, char *str, int len, int type)
{
	if (word->elem_cnt == word->alloc_size)
		__grow_word_element_array__(word);
	word->elem_arr[word->elem_cnt].data = str;
	word->elem_arr[word->elem_cnt].len = len;
	word->elem_arr[word->elem_cnt].type = type;
	word->elem_cnt++;
// printf("word->elem_cnt: %d\n", word->elem_cnt);
}

void	push_elem_to_cur_word(t_words *words, char *str, int len, int type)
{
	t_word	*word;

	word = get_cur_word(words);
// printf("word count: %d\n", words->word_cnt);
// printf("str: %s, len: %d\n", str, len);
	push_elem_to_word(word, str, len, type);
}

void	push_elem_to_new_word(t_words *words, char *str, int len, int type)
{
	t_word	*word;

	word = get_new_word(words);
	push_elem_to_word(word, str, len, type);
}

void	mask_cur_word(t_words *words, int mask)
{
	t_word	*word;

	word = get_cur_word(words);
	word->mask |= mask;
}