/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_mask_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:49:22 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:17:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion_internal_bonus.h"

void	mask_cur_word(t_words *words, int mask)
{
	t_word	*word;

	word = get_cur_word(words);
	word->mask |= mask;
}
