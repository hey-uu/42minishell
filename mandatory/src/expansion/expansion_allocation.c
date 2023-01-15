/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_expansion_set.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:00:10 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/15 23:12:14 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "env_manager.h"
#include "libft.h"
#include <stddef.h>

char	*ft_strndup(char *str, int n);

t_word	*create_word_node(void)
{
	t_word	*new;

	new = ft_malloc(sizeof(t_word));
	new->data = NULL;
	new->len = 0;
	new->quote = EXP_UNQUOTED;
	new->next = NULL;
	return (new);
}

t_expansion	*create_expansion_set(char *origin, t_env_tab *envtab)
{
	t_expansion	*new;

	new = ft_malloc(sizeof(t_expansion));
	new->origin = origin;
	new->origin_len = ft_strlen(origin);
	new->head = NULL;
	new->last = NULL;
	new->count = 0;
	return (new);
}

t_word	*add_new_word_node_back(t_expansion *set)
{
	t_word	*new;

	new = create_word_node();
	if (!set->head)
	{
		set->head = new;
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
