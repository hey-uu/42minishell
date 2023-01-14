/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 00:07:40 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/15 00:22:29 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager.h"

void	env_set(t_env_tab *table, char *variable, char *value)
{
	hash_table_update(table, variable, value);
}

void	env_unset(t_env_tab *table, char *variable)
{
	hash_table_delete(table, variable);
}