/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:01:42 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/14 11:43:29 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tem;

	if (!lst || !f)
		return ;
	while (lst)
	{
		tem = lst;
		lst = lst->next;
		f(tem->content);
	}
}
