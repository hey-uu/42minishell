/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_stat_manager.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 00:40:36 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 02:36:05 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_STAT_MANAGER_H
# define EXIT_STAT_MANAGER_H

/*-------------- FUNCTION PROTOTYPES -------------*/

int		exit_stat_get(void);
char	*exit_stat_get_dup_str(void);
char	*exit_stat_get_str(void);
int		exit_stat_update(int new_stat);
void	exit_program(void);

#endif