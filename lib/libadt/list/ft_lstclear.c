/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:01:22 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/10 19:11:01 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tem;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tem = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(tem, del);
	}
}
