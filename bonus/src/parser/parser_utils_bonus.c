/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:17:32 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:17:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_internal_bonus.h"

int	is_redirection(int token_type)
{
	if (token_type == TOKEN_REDIR_IN || token_type == TOKEN_REDIR_IN_HERE || \
		token_type == TOKEN_REDIR_OUT || token_type == TOKEN_REDIR_OUT_APP)
		return (1);
	return (0);
}

int	false_push_redirect(t_queue *q_redir_list, t_token *tokens, int *offset)
{
	if (!((tokens[*offset].type == TOKEN_WORD)
			&& push_redirect(q_redir_list, tokens, *offset - 1) == SUCCESS))
		return (1);
	return (0);
}
