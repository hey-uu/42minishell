/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:09:33 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/17 11:10:11 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LIST_H
# define T_LIST_H

/*------------- STRUCT DECLARATIONS --------------*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

#endif
