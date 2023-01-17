/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_internal.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 02:10:39 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/17 11:50:37 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_INTERNAL_H
# define QUEUE_INTERNAL_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "t_queue.h"

/*-------------- FUNCTION PROTOTYPES -------------*/

char		*queue_pop_str(t_queue *queue);
int			__queue_double_size__(t_queue *queue);

#endif