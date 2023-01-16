/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_allocation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:00:10 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 23:22:13 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "expansion_internal.h"
#include "libft.h"

static t_word	*create_word_node(void)
{
	t_word	*new;

	new = ft_malloc(sizeof(t_word));
	new->data = NULL;
	new->len = 0;
	new->mask = EXPAND_NONE;
	new->next = NULL;
	return (new);
}

t_expansion	*create_expansion_set(char *origin)
{
	t_expansion	*new;

	new = ft_malloc(sizeof(t_expansion));
	new->origin = origin;
	new->origin_len = ft_strlen(origin);
	new->first = NULL;
	new->last = NULL;
	new->count = 1;
	return (new);
}

t_word	*add_new_word_node_back(t_expansion *set)
{
	t_word	*new;

	new = create_word_node();
	if (!set->first)
	{
		set->first = new;
		set->last = new;
	}
	else
	{
		set->last->next = new;
		set->last = new;
	}
	return (new);
}

void	dup_data_to_word(t_word *node, char *word)
{
	if (!node->len)
		return ;
	node->data = ft_strndup(word, node->len);
}
