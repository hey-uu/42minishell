/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_env_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 03:45:50 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 20:07:12 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager_internal.h"

char	*env_get(char *variable)
{
	return (env_manager(ENV_GET, NULL, variable, NULL));
}

char	*env_dup_val(char *variable)
{
	char	*value;

	value = env_manager(ENV_GET, NULL, variable, NULL);
	if (!value)
		return (value);
	return (ft_strdup(value));
}

char	**env_get_defined_variable_list(void)
{
	return (env_manager(ENV_GET_DEFINED_VAR_LIST, NULL, NULL, NULL));
}

char	**env_get_marked_variable_list(void)
{
	return (env_manager(ENV_GET_MARKED_VAR_LIST, NULL, NULL, NULL));
}
