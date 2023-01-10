/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd_argv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:03:48 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/11 00:17:40 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void	push_arguments(t_simple_cmd *simple_cmd, t_token *token, int offset)
{
	const char	*str = ft_strdup(token[offset].str);

	queue_push_str(simple_cmd->argv, (char *)str);
}
