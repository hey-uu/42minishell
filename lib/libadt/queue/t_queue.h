/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_queue.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:15:38 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/24 13:01:40 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_QUEUE_H
# define T_QUEUE_H

# include "libadt_type.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

typedef enum e_queue_type
{
	QUEUE_INT_ONLY,
	QUEUE_STR_ONLY,
	QUEUE_INTSTR
}	t_queue_type;

/*------------- STRUCT DECLARATIONS --------------*/

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

#endif
