/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dynamic_array.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:15:38 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/24 13:01:48 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_DYNAMIC_ARRAY_H
# define T_DYNAMIC_ARRAY_H

# include "libadt_type.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum e_dynamic_array_type
{
	DARR_INT,
	DARR_STR,
	DARR_INTSTR
};

/*------------- STRUCT DECLARATIONS --------------*/

typedef struct s_dynamic_array
{
	int				type;
	int				*iarr;
	char			**strarr;
	t_intstr		*istrarr;
	int				used_size;
	int				size;
}	t_dynamic_array;

typedef t_dynamic_array	t_darr;

#endif
