/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:43:40 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/15 14:22:20 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H

enum e_is_quoted
{
	EXP_NONE,
	EXP_DQUOTED,
	EXP_SQUOTED
};

typedef struct s_expansion
{
	t_queue	*words;
	t_queue	*len;
	int		cnt;
	
}	t_expansion;


#endif