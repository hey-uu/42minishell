/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_internal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:09:22 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/10 19:13:45 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_INTERNAL_H
# define LIST_INTERNAL_H

/*------------- STRUCT DECLARATIONS --------------*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*-------------- FUNCTION PROTOTYPES -------------*/

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));

#endif