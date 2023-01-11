/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_unit_redir_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:03:05 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/11 10:57:59 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

int	is_redirection(int type)
{
	if (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_IN_HERE || \
		type == TOKEN_REDIR_OUT || type == TOKEN_REDIR_OUT_APP)
		return (1);
	return (0);
}

t_queue	*create_redirect_list(void)
{
	t_queue	*new;

	new = create_queue(QUEUE_INITIAL_SIZE, QUEUE_INTSTR);
	return (new);
}

void	push_redirection(t_queue *redir_list, t_token *token, int offset)
{
	const int	type = token[offset].type;
	char		*str;

	if (token[offset + 1].str)
		str = ft_strdup(token[offset + 1].str);
	else
		return ;
	queue_push_intstr(redir_list, (int)type, (char *)str);
}
