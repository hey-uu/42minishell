/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_env_set_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 03:46:28 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:17:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager_internal_bonus.h"

char	*env_set(char *variable, char *value)
{
	return (env_manager(ENV_SET, NULL, variable, value));
}

char	*env_unset(char *variable)
{
	return (env_manager(ENV_UNSET, NULL, variable, NULL));
}
