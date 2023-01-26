/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:33:19 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 08:04:08 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "executor.h"

int	executor(t_node *parse_tree)
{
	if (execute_list(parse_tree) == SUCCESS)
		return (SUCCESS);
	else
		return (FAILURE);
}
