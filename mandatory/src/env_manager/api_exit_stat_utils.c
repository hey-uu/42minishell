/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_exit_stat_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:33:08 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 23:51:45 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager_internal.h"
#include "libft.h"

int	exit_stat_get(void)
{
	return (exit_stat_manager(EXIT_STAT_GET, 0));
}

char	*exit_stat_get_str(void)
{
	return (ft_itoa(exit_stat_manager(EXIT_STAT_GET, 0)));
}

int	exit_stat_update(int new_stat)
{
	return (exit_stat_manager(EXIT_STAT_UPDATE, new_stat));
}

void	exit_program(void)
{
	exit_stat_manager(EXIT_PROGRAM, 0);
}
