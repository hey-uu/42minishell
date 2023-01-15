/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_env_initialize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:39:27 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 15:39:31 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager_internal.h"

t_env_tab	*init_env_table(char **envp)
{
	return (env_manager(ENV_INIT, envp, NULL, NULL));
}
