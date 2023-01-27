/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_exit_program.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:08:01 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 20:08:03 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_stat_manager_internal.h"

void	exit_program(void)
{
	exit_stat_manager(EXIT_PROGRAM, 0);
}
