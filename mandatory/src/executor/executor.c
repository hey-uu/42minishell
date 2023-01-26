/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:33:19 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 21:11:58 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"
#include "executor.h"
#include "minishell.h"
#include "parser.h"
#include "env_manager.h"

void	executor(t_node *parse_tree, int *errcode)
{
	if (*errcode)
		return ;
	if (execute_list(parse_tree) == FAILURE)
		*errcode = ERROR_EXECUTE_FAILED;
}
