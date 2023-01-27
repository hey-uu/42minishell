/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 00:10:33 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 20:35:19 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "s_token.h"
#include "s_tree_node.h"
#include "handle_error.h"
#include "expansion_internal.h"

void	expand_cmd_name(char **cmd)
{
	t_darr	strings;
	int		i;

	if (!*cmd)
		return ;
	init_dynamic_array(&strings, INITIAL_DARR_SIZE, DARR_STR);
	expand_word_to_strings(*cmd, &strings);
	free(*cmd);
	*cmd = strings.strarr[0];
	i = 1;
	while (i < strings.used_size)
	{
		free(strings.strarr[i]);
		i++;
	}
	free(strings.strarr);
}

void	expand_cmd_argv(t_queue **q_cmd_argv, t_string **cmd_argv)
{
	char		*argument;
	t_darr		strings;
	int			i;

	init_dynamic_array(&strings, INITIAL_DARR_SIZE, DARR_STR);
	i = 0;
	while (i < (*q_cmd_argv)->used_size)
	{
		argument = queue_get_str(*q_cmd_argv, i);
		expand_word_to_strings(argument, &strings);
		i++;
	}
	destroy_queue(q_cmd_argv);
	*cmd_argv = strings.strarr;
}

void	process_ambiguous_redirect_error(t_darr *strings, int i, char *arg)
{
	int	j;

	strings->istrarr[i] = (t_intstr){ERR_EXE_AMBIGUOUS_REDIR, ft_strdup(arg)};
	j = i;
	while (j < strings->used_size)
	{
		free(strings->strarr[j]);
		strings->strarr[j] = NULL;
		j++;
	}
}

void	expand_redir_list(t_queue **q_redir_list, t_intstr **redir_list)
{
	t_intstr	qdata;
	t_darr		strings;
	int			i;

	init_dynamic_array(&strings, INITIAL_DARR_SIZE, DARR_INTSTR);
	i = 0;
	while (i < (*q_redir_list)->used_size)
	{
		qdata = queue_get_intstr(*q_redir_list, i);
		expand_word_to_strings(qdata.str, &strings);
		if (strings.strarr[i] == NULL || strings.used_size != i + 1)
		{
			process_ambiguous_redirect_error(&strings, i, qdata.str);
			break ;
		}
		strings.istrarr[i] = (t_intstr){qdata.num, strings.strarr[i]};
		i++;
	}
	darr_push_intstr(&strings, TOKEN_NONE, NULL);
	destroy_queue(q_redir_list);
	free(strings.iarr);
	free(strings.strarr);
	*redir_list = strings.istrarr;
}

void	do_expansion(t_execute_unit *exe_unit)
{
	expand_cmd_name(&exe_unit->cmd_name);
	expand_cmd_argv(&exe_unit->q_cmd_argv, &exe_unit->cmd_argv);
	expand_redir_list(&exe_unit->q_redir_list, &exe_unit->redir_list);
}
