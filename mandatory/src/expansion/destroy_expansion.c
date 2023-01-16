/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:00:32 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 09:01:39 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include <stdlib.h>

void	destroy_words(t_word *word)
{
	t_word	*cur;
	t_word	*next;

	cur = word;
	while (cur)
	{
		next = cur->next;
		free(cur->data);
		free(cur);
		cur = next;
	}
}

void	destroy_expansion(t_expansion *set)
{
	destroy_words(set->first);
	free(set);
}