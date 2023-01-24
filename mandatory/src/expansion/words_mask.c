/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_mask.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:49:22 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/24 22:49:30 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion_internal.h"

void	mask_cur_word(t_words *words, int mask)
{
	t_word	*word;

	word = get_cur_word(words);
	word->mask |= mask;
}
