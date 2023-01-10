/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 02:10:39 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/10 19:09:05 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_INTERNAL_H
# define QUEUE_INTERNAL_H

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

t_queue		*create_queue(int initial_size, int type);
void		destroy_queue(t_queue *queue);
int			queue_double_size(t_queue *queue);
int			queue_pop_int(t_queue *deq);
char		*queue_pop_str(t_queue *deq);
t_intstr	queue_pop_intstr(t_queue *deq);
void		queue_push_int(t_queue *queue, int new_data);
void		queue_push_str(t_queue *queue, char *new_data);
void		queue_push_intstr(t_queue *queue, int idata, char *sdata);
void		queue_show(t_queue *queue);

#endif