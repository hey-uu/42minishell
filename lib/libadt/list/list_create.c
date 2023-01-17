/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:41:31 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/17 11:41:40 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
#include "t_list.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_lst;

	new_lst = ft_malloc(sizeof(t_list));
	new_lst->content = content;
	new_lst->next = NULL;
	return (new_lst);
}
