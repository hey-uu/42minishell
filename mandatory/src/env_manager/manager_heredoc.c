/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:10:38 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 10:32:34 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_env_table.h"

int	heredoc_manager(int option, int new_stat, char *new_file_name, int new_fd)
{
	static int	heredoc_stat;
	static char	*heredoc_file_name;
	static int	heredoc_fd;

	if (option == HEREDOC_STAT_UPDATE)
	{
		heredoc_stat = new_stat;
		heredoc_file_name = new_file_name;
		heredoc_fd = new_fd;
	}
	if (option == HEREDOC_STAT_GET)
		return (heredoc_stat);
	return (0);
}
