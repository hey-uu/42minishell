/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 09:34:05 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/06 11:04:57 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

struct s_ivector
{
	int	used_size;
	int	capacity;
	int	*array;
};

typedef struct s_ivector*	t_ivector;

t_ivector	ivec_create(int size);
void		ivec_destroy(t_ivector vector);
void		ivec_add(t_ivector vector, int data);
void		ivec_add_at(t_ivector vector, int idx, int data);
void		ivec_put(t_ivector vector, int idx, int data);
void		ivec_get(t_ivector vector, int idx);
void		ivec_remove(t_ivector vector);
void		ivec_remove_at(t_ivector vector, int idx);

#endif