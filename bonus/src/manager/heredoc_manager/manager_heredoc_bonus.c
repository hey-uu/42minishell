/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_heredoc_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:10:38 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:17:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heredoc_manager_internal_bonus.h"

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
