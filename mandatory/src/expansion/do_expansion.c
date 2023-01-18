/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:55:51 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 15:38:11 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "expansion_internal.h"
#include "s_tree_node.h"

char	**expand_word_to_strings(char *word)
{
	t_expansion	*set;
	char		**strings;

// printf("> expand word to strings...\n");
	set = expand_word(word);
	strings = words_to_strings(word);
	destroy_expansion(set);
	return (strings);
}

void	expand_cmd(char **cmd)
{
	char		**strings;
	int			i;

// printf("> expand cmd!\n");
	strings = expand_word_to_strings(*cmd);
	free(*cmd);
	*cmd = strings[0];
	i = 1;
	while (strings[i])
	{
		free(strings[i]);
		i++;
	}
	free(strings);
}

void	expand_cmd_argv(t_queue **cmd_argv)
{
	const int	old_used_size = (*cmd_argv)->used_size;
	char		*argument;
	char		**strings;
	int			i;

// printf("> expand cmd argv!\n");
	i = 0;
	while (i < old_used_size)
	{
		argument = queue_pop_str(*cmd_argv);
		strings = expand_word_to_strings(argument);
		queue_push_strs(*cmd_argv, strings);
		free(strings);
		i++;
	}
}

int	expand_redir_list(t_queue **redir_list)
{
	const int	old_used_size = (*redir_list)->used_size;
	char		**strings;
	int			i;
	t_intstr	qdata;

// printf("> expand redirection list!\n");
	i = -1;
	while (++i < old_used_size)
	{
		qdata = queue_pop_intstr(*redir_list);
		strings = expand_word_to_strings(qdata.str);
		if (strings[0] && strings[1])
		{
			free_double_char_array(&strings);
//error messge
			printf("goldsh: %s: ambiguous redirect\n", qdata.str);
			return (EXPAND_AMBIGUOUS_REDIRECT_ERROR);
		}
		else
			queue_push_intstr(*redir_list, qdata.num, strings[0]);
		free(strings);
	}
	return (EXPAND_SUCCESS);
}

int	do_expansion(t_execute_unit *exe_unit)
{
	int	res;

	expand_cmd(&exe_unit->cmd_name);
	expand_cmd_argv(&exe_unit->cmd_argv);
	res = expand_redir_list(&exe_unit->redir_list);
	return (res);
}
