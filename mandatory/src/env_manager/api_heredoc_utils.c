/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_heredoc_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:21:19 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/26 17:14:52 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager_internal.h"
#include "s_token.h"
#include "wrap.h"
#include <unistd.h>

void	heredoc_init(void)
{
	heredoc_manager(HEREDOC_INIT, 0, NULL, NULL);
}

int	heredoc_stat_get(void)
{
	return (heredoc_manager(HEREDOC_STAT_GET, 0, NULL, NULL));
}

void	heredoc_in_process(t_queue *new_redir_list)
{
	heredoc_manager(\
	HEREDOC_STAT_UPDATE, HEREDOC_IN_PROCESS, new_redir_list, NULL);
}

void	heredoc_done(void)
{
	heredoc_manager(HEREDOC_STAT_UPDATE, HEREDOC_DONE, NULL, NULL);
}

void	heredoc_interupted(char *cur_heredoc_file)
{
	t_queue	*cur_redir_list;
	int		i;

	w_unlink(cur_heredoc_file);
	heredoc_manager(HEREDOC_GET_REDIR_LIST, 0, NULL, &cur_redir_list);
	if (!cur_redir_list)
		return ;
	i = 0;
	while (i < cur_redir_list->used_size)
	{
		if (queue_get_int(cur_redir_list, i) == TOKEN_REDIR_IN_HERE)
		{
			w_unlink(queue_get_str(cur_redir_list, i));
			i++;
		}
	}
	exit_stat_update(1);
	heredoc_manager(HEREDOC_STAT_UPDATE, HEREDOC_INTSIG, NULL, NULL);
}
