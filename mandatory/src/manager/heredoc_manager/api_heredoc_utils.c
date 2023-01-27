/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_heredoc_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:21:19 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 20:21:13 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc_manager_internal.h"

static void	__unlink_heredoc_files__(t_queue *q_redir_list)
{
	int		i;
	char	*filename;

	i = 0;
	while (i < q_redir_list->used_size)
	{
		if (queue_get_int(q_redir_list, i) == TOKEN_REDIR_IN_HERE)
		{
			filename = queue_get_str(q_redir_list, i);
			w_unlink(filename);
		}
		i++;
	}
}

static void	__unlink_all_heredoc_files__(t_node *node)
{
	if (!node)
		return ;
	__unlink_all_heredoc_files__(node->first_child);
	__unlink_all_heredoc_files__(node->next_sibling);
	if (node->exe_unit && node->exe_unit->q_redir_list)
		__unlink_heredoc_files__(node->exe_unit->q_redir_list);
}

void	heredoc_init(t_node *root)
{
	heredoc_manager(HEREDOC_INIT, 0, root, NULL);
}

int	heredoc_stat_get(void)
{
	return (heredoc_manager(HEREDOC_STAT_GET, 0, NULL, NULL));
}

void	heredoc_interupted(char *cur_heredoc_file)
{
	t_node	*root;

	exit_stat_update(1);
	heredoc_manager(HEREDOC_STAT_UPDATE, HEREDOC_INTSIG, NULL, NULL);
	w_unlink(cur_heredoc_file);
	heredoc_manager(HEREDOC_GET_PARSE_TREE, 0, NULL, &root);
	__unlink_all_heredoc_files__(root);
}
