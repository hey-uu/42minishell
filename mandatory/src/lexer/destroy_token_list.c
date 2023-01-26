/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_token_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:43:44 by yona              #+#    #+#             */
/*   Updated: 2023/01/27 07:35:38 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lexer_internal.h"

void	destroy_token_list(t_token *token_list)
{
	int	i;

	if (!token_list)
		return ;
	i = 0;
	while (token_list[i].type != TOKEN_NONE)
	{
		if (token_list[i].str)
			free(token_list[i].str);
		i++;
	}
	free(token_list);
}
