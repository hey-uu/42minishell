/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_unit_redir_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:03:05 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/11 00:17:31 by hyeyukim         ###   ########.fr       */
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

t_redir_list	*create_redirect_list(void)
{
	t_redir_list	*new;

	new = ft_malloc(sizeof(t_redir_list));
	new->redir_in = create_queue(QUEUE_INITIAL_SIZE, QUEUE_INTSTR);
	new->redir_out = create_queue(QUEUE_INITIAL_SIZE, QUEUE_INTSTR);
	return (new);
}

void	push_redirection(t_redir_list *io_list, t_token *token, int offset)
{
	const int	type = token[offset].type;
	const char	*str = ft_strdup(token[offset + 1].str);

	if (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_IN_HERE)
		queue_push_intstr(io_list->redir_in, (int)type, (char *)str);
	else
		queue_push_intstr(io_list->redir_out, (int)type, (char *)str);
}
