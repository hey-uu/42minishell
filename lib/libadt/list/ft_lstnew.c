/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:02:00 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/10 19:11:01 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_internal.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new_lst;

	new_lst = malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	new_lst->content = content;
	new_lst->next = NULL;
	return (new_lst);
}
