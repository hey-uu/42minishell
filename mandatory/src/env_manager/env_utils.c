/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:08:45 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 21:32:16 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager_internal.h"

t_env_tab	*initialize_env_table(char **envp)
{
	return (env_manager(ENV_INIT, envp, NULL, NULL));
}

char	*env_set(char *variable, char *value)
{
	return (env_manager(ENV_SET, NULL, variable, value));
}

char	*env_unset(char *variable)
{
	return (env_manager(ENV_UNSET, NULL, variable, NULL));
}

char	*env_get(char *variable)
{
	return (env_manager(ENV_GET, NULL, variable, NULL));
}

char	**env_tab_to_arr(void)
{
	return (env_manager(ENV_TAB_TO_ARR, NULL, NULL, NULL));
}
