/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:38:17 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/14 01:55:58 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash_table_internal.h"
#include "libft.h"

t_hash_tab	*hash_create(int bucket_cnt)
{
	t_hash_tab	*new;

	new = ft_malloc(sizeof(t_hash_tab));
	new->arr = ft_malloc(sizeof(t_hash_content *) * bucket_cnt);
	new->bucket_cnt = bucket_cnt;
	new->entry_cnt = 0;
	return (new);
}

void	hash_destroy(t_hash_tab *table)
{
	
}

t_hash_tab	*hash_resize()
{
	
}
