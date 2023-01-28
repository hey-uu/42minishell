/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pattern_feature_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 22:17:55 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:17:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion_internal_bonus.h"

int	get_pattern_char(t_word *word, int i)
{
	int				tem;
	int				len;
	unsigned char	c;
	int				j;

	tem = -1;
	j = -1;
	while (i > tem)
	{
		len = word->elem_arr[++j].len;
		tem += len;
	}
	if (word->elem_arr[j].type & WELEM_WILDCARD)
		return (IS_WILDCARD);
	if (i == tem)
		c = (unsigned char)word->elem_arr[j].data[len - 1];
	else
		c = (unsigned char)word->elem_arr[j].data[i - tem + len - 1];
	return ((int)c);
}

int	get_pattern_len(t_word *word)
{
	int	pattern_len;
	int	i;

	i = 0;
	pattern_len = 0;
	while (i < word->elem_cnt)
	{
		pattern_len += word->elem_arr[i].len;
		i++;
	}
	return (pattern_len);
}
