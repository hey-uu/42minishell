/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libadt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:58:02 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/10 19:04:11 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBADT_H
# define LIBADT_H

/*------------- STRUCT DECLARATIONS --------------*/

// linked list
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// queue
typedef enum e_queue_type
{
	QUEUE_INT_ONLY,
	QUEUE_STR_ONLY,
	QUEUE_INTSTR
}	t_queue_type;

typedef struct s_queue
{
	t_queue_type	type;
	int				*iarr;
	char			**strarr;
	int				front;
	int				rear;
	int				size;
	int				used_size;
}	t_queue;

typedef struct s_intstr
{
	int		num;
	char	*str;
}	t_intstr;

/*-------------- FUNCTION PROTOTYPES -------------*/

// linked list
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);

// queue
t_queue		*create_queue(int initial_size, int type);
void		destroy_queue(t_queue *queue);
int			queue_pop_int(t_queue *deq);
char		*queue_pop_str(t_queue *deq);
t_intstr	queue_pop_intstr(t_queue *deq);
void		queue_push_int(t_queue *queue, int new_data);
void		queue_push_str(t_queue *queue, char *new_data);
void		queue_push_intstr(t_queue *queue, int idata, char *sdata);
void		queue_show(t_queue *queue);

#endif