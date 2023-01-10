/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:03:05 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/10 16:22:28 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	const char	*str = token[offset + 1].str;

	if (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_IN_HERE)
		queue_push_intstr(io_list->redir_in, (int)type, (char *)str);
	else
		queue_push_intstr(io_list->redir_out, (int)type, (char *)str);
}
