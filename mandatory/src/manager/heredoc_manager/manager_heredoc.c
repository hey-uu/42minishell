/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:10:38 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 20:12:53 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc_manager_internal.h"

int	heredoc_manager(int option, int new_stat, t_node *root, t_node **root_ptr)
{
	static int		heredoc_stat;
	static t_node	*target;

	if (option == HEREDOC_INIT)
	{
		heredoc_stat = HEREDOC_NONE;
		target = root;
	}
	else if (option == HEREDOC_STAT_UPDATE)
	{
		heredoc_stat = new_stat;
	}
	else if (option == HEREDOC_STAT_GET)
	{
		return (heredoc_stat);
	}
	else if (option == HEREDOC_GET_PARSE_TREE)
	{
		*root_ptr = target;
	}
	return (0);
}
