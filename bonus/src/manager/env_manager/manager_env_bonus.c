/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_env_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:34:32 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:17:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager_internal_bonus.h"

void	*env_manager(int option, char *envp[], char *variable, char *value)
{
	static t_env_tab	envtab;

	if (option == ENV_INIT)
		return ((void *)__env_table_init__(&envtab, envp));
	else if (option == ENV_SET)
		return ((void *)__env_set__(&envtab, variable, value));
	else if (option == ENV_UNSET)
		return ((void *)__env_unset__(&envtab, variable));
	else if (option == ENV_GET)
		return ((void *)__env_get__(&envtab, variable));
	else if (option == ENV_GET_MARKED_VAR_LIST)
		return ((void *)__env_get_marked_variable_list__(&envtab));
	else if (option == ENV_GET_DEFINED_VAR_LIST)
		return ((void *)__env_get_defined_variable_list__(&envtab));
	return (NULL);
}
