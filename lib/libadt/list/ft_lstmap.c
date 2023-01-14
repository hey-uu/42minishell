/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:01:53 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/14 11:43:29 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"

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
