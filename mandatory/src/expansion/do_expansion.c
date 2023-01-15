/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:55:51 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/15 23:51:52 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "expansion_internal.h"
#include "s_tree_node.h"
#include <stdio.h>

char	**expand_word_to_strings(char *word)
{
	t_expansion	*set;
	char		**strings;

// printf("> expand word to strings...\n");
	set = expand_word(word);
	strings = words_to_strings(set);
	destroy_expansion(set);
	return (strings);
}

void	expand_cmd_name(char **cmd)
{
	char		**strings;
	int			i;

// printf("> expand cmd!\n");
// assert(*cmd != NULL);
	strings = expand_word_to_strings(*cmd);
	free(*cmd);
	*cmd = strings[0];
// printf("cmd: %s\n", *cmd);
	i = 1;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

void	expand_cmd_argv(t_queue **q_cmd_argv)
{
	const int	old_used_size = (*q_cmd_argv)->used_size;
	char		*argument;
	char		**strings;
	int			i;

// printf("> expand cmd argv!\n");
	i = 0;
	while (i < old_used_size)
	{
		argument = queue_pop_str(*q_cmd_argv);
		strings = expand_word_to_strings(argument);
		free(argument);
		queue_push_strs(*q_cmd_argv, strings);
		free(strings);
		i++;
	}
}

int	expand_redir_list(t_queue **q_redir_list)
{
	const int	old_used_size = (*q_redir_list)->used_size;
	char		**strings;
	int			i;
	t_intstr	qdata;

// printf("> expand redirection list!\n");
	i = -1;
	while (++i < old_used_size)
	{
		qdata = queue_pop_intstr(*q_redir_list);
		strings = expand_word_to_strings(qdata.str);
		if (strings[0] && strings[1])
		{
			free_double_char_array(&strings);
//error messge
			dprintf(2, "goldsh: %s: ambiguous redirect\n", qdata.str);
			return (EXPAND_AMBIGUOUS_REDIRECT_ERROR);
		}
		else
			queue_push_intstr(*q_redir_list, qdata.num, strings[0]);
		free(strings);
	}
	return (EXPAND_SUCCESS);
}

int	do_expansion(t_execute_unit *exe_unit)
{
	int	res;

	res = 0;
	expand_cmd_name(&exe_unit->cmd_name);
	expand_cmd_argv(&exe_unit->q_cmd_argv);
	exe_unit->cmd_argv = queue_get_str_arr(exe_unit->q_cmd_argv);
	res = expand_redir_list(&exe_unit->q_redir_list);
	exe_unit->redir_list = queue_get_intstr_arr(exe_unit->q_redir_list);
	return (res);
}
