/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:55:51 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/15 23:12:38 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "expansion.h"
#include "env_manager.h"

void	do_expansion(t_execute_unit *exe_unit, t_env_tab *env_tab)
{
	exe_unit->cmd_name = expand_cmd(exe_unit->cmd_name);
	expand_cmd_argv(exe_unit->cmd_argv);
	expand_redir_list(exe_unit->redir_list);
}
