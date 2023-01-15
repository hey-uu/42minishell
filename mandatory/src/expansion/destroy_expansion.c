/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:00:32 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 07:03:23 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include <stdlib.h>

void	destroy_expansion(t_expansion *set)
{
	t_word	*node;
	t_word	*next;

	node = set->first;
	while (node)
	{
		next = node->next;
		free(node->data);
		free(node);
		node = next;
	}
	free(set);
}