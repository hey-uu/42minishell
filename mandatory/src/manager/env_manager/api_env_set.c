/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_env_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 03:46:28 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/21 07:10:34 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager_internal.h"

char	*env_set(char *variable, char *value)
{
	return (env_manager(ENV_SET, NULL, variable, value));
}

char	*env_unset(char *variable)
{
	return (env_manager(ENV_UNSET, NULL, variable, NULL));
}
