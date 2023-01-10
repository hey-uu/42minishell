/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:03:48 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/10 16:12:39 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	push_arguments(t_simple_cmd *simple_cmd, t_token *token, int offset)
{
	const char	*str = token[offset].str;

	queue_push_str(simple_cmd->argv, (char *)str);
}