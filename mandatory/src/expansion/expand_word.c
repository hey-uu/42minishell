/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:44:03 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/15 14:27:51 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "libadt.h"

t_expansion	create_expansion(void)
{
	t_expansion	*new;

	new->words = create_queue(QUEUE_INITIAL_SIZE);
	
}

t_expansion	*expand_word(char *word)
{
	t_expansion	*set;

	set = 
}