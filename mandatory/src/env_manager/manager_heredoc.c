/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:10:38 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 23:42:30 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env_manager_internal.h"
#include "libadt.h"

int	heredoc_manager(\
	int option, int new_stat, t_queue *new_redir_list, t_queue **cur_redir_list)
{
	static int		heredoc_stat;
	static t_queue	*redir_list;

	if (option == HEREDOC_INIT)
	{
		heredoc_stat = HEREDOC_NONE;
		redir_list = NULL;
	}
	if (option == HEREDOC_STAT_UPDATE)
	{
		heredoc_stat = new_stat;
		if (new_stat == HEREDOC_IN_PROCESS)
			redir_list = new_redir_list;
		if (new_stat == HEREDOC_DONE)
			redir_list = NULL;
	}
	else if (option == HEREDOC_STAT_GET)
		return (heredoc_stat);
	else if (option == HEREDOC_STAT_GET)
		*cur_redir_list = redir_list;
	return (0);
}
