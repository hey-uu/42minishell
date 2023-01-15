/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:55:51 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 00:14:37 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "expansion.h"
#include "env_manager.h"

char	*expand_cmd(char *cmd, t_env_tab *envtab)
{
	
}

void	expand_cmd_argv(t_queue *cmd_argv, t_env_tab *envtab)
{
	char	*popped;
	t_word	*word;

	popped = queue_pop_str(cmd_argv);
	word = expand_word(popped, envtab);
	
}

void	expand_redir_list(t_queue *redir_list, t_env_tab *envtab)
{
	
}

void	do_expansion(t_execute_unit *exe_unit, t_env_tab *envtab)
{
	exe_unit->cmd_name = expand_cmd(exe_unit->cmd_name, envtab);
	expand_cmd_argv(exe_unit->cmd_argv, envtab);
	expand_redir_list(exe_unit->redir_list, envtab);
}
