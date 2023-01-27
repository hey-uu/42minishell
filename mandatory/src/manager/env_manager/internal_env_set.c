/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_env_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 03:53:28 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 20:06:54 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager_internal.h"

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
