/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:21:19 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 10:30:19 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager_internal.h"

void	heredoc_is_in_process(char *file_name, int fd)
{
	heredoc_manager(HEREDOC_STAT_UPDATE, HEREDOC_IN_PROCESS, file_name, fd);
}

void	heredoc_is_done(void)
{
	heredoc_manager(HEREDOC_STAT_UPDATE, HEREDOC_DONE, NULL, -1);
}

int	heredoc_stat_get(void)
{
	return (heredoc_manager(HEREDOC_STAT_GET, 0, NULL, -1));
}
