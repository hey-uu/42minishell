/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:34:32 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/26 22:52:30 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager_internal.h"

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
