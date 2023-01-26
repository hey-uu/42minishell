/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:10:38 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/26 17:52:16 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env_manager_internal.h"
#include "s_tree_node.h"

int	heredoc_manager(\
	int option, int new_stat, t_node *cur_root, t_node **root_ptr)
{
	static int		heredoc_stat;
	static t_node	*root;

	if (option == HEREDOC_INIT)
	{
		heredoc_stat = HEREDOC_NONE;
		root = cur_root;
	}
	else if (option == HEREDOC_STAT_UPDATE)
		heredoc_stat = new_stat;
	else if (option == HEREDOC_STAT_GET)
		return (heredoc_stat);
	else if (option == HEREDOC_STAT_GET)
		*root_ptr = cur_root;
	return (0);
}
