/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_env_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:39:27 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:17:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager_internal_bonus.h"

t_env_tab	*init_env_table(char **envp)
{
	return (env_manager(ENV_INIT, envp, NULL, NULL));
}
