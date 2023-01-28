/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_execute_unit_content.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:49:32 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 15:51:54 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tree_internal.h"

char	*process_heredoc(char *word);

void	push_arguments(t_queue *q_cmd_argv, t_token *token, int offset)
{
	char	*str;

	if (token[offset].str)
		str = ft_strdup(token[offset].str);
	else
		return ;
	queue_push_str(q_cmd_argv, str);
}

int	push_redirect(t_queue *q_redir_list, t_token *token, int offset)
{
	const int	type = token[offset].type;
	char		*str;

	str = NULL;
	if (type == TOKEN_REDIR_IN_HERE)
		str = process_heredoc(token[offset + 1].str);
	else if (token[offset + 1].str)
		str = ft_strdup(token[offset + 1].str);
	if (!str)
		return (FAILURE);
	queue_push_intstr(q_redir_list, (int)type, (char *)str);
	return (SUCCESS);
}
