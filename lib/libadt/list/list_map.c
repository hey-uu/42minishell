/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:43:20 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/17 11:43:26 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "list_internal.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*cur;

	if (!lst || !f)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (NULL);
	cur = new_lst;
	while (lst->next)
	{
		lst = lst->next;
		cur->next = ft_lstnew(f(lst->content));
		cur = cur->next;
		if (!cur)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
	}
	return (new_lst);
}
