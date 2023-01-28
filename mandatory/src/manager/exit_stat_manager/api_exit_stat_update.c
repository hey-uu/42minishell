/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_exit_stat_update.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:59:17 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/28 12:59:18 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_stat_manager_internal.h"

int	exit_stat_update(int new_stat)
{
	return (exit_stat_manager(EXIT_STAT_UPDATE, new_stat));
}
