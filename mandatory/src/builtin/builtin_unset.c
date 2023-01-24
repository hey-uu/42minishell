/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 02:06:33 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 02:22:06 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "builtin_internal.h"
#include "env_manager.h"
#include "error.h"
#include "libft.h"

void	builtin_unset(char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		env_unset(argv[i]);
		free(argv[i]);
		i++;
	}
	free(argv);
	exit_stat_update(0);
}
