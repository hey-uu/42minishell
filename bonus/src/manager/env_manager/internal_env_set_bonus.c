/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_env_set_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 03:53:28 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:17:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager_internal_bonus.h"

t_env_tab	*__env_set__(t_env_tab *table, char *variable, char *value)
{
	if (!variable)
		return (NULL);
	hash_table_update(table, variable, value);
	return (table);
}

t_env_tab	*__env_unset__(t_env_tab *table, char *variable)
{
	if (!variable)
		return (NULL);
	hash_table_delete(table, variable);
	return (table);
}
