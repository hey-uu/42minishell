/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:34:32 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 15:39:07 by hyeyukim         ###   ########.fr       */
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
	else if (option == ENV_TAB_TO_ARR)
		return ((void *)__env_tab_to_arr__(&envtab));
	return (NULL);
}
