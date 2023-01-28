/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_exit_program_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:08:01 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:17:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_stat_manager_internal_bonus.h"

void	exit_program(void)
{
	exit_stat_manager(EXIT_PROGRAM, 0);
}
