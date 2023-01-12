/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_token_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:43:44 by yona              #+#    #+#             */
/*   Updated: 2023/01/12 19:59:05 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
