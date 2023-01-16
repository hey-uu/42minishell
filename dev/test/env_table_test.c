/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_table_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:13:43 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 21:53:01 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include "libft.h"
#include "libadt.h"
#include "t_env_table.h"
#include "env_manager.h"

#define VARIABLE "PATH"
#define USR_VARIABLE "hyeyun"
#define USR_VALUE "please... help..."

void	show_hash_table(t_hash_table *table);

void	check(void)
{
	system("leaks env_test");
}

int	main(int argc, char *argv[], char *envp[])
{
	t_env_tab	*table;
	char		*value;

	atexit(check);
	argc++;
	argv++;
	table = initialize_env_table(envp);
	show_hash_table(table);
	printf("\n\n* trying to get value of %s\n", VARIABLE);
	value = env_get(VARIABLE);
	printf("%s : %s\n", VARIABLE, value);
	printf("===> get success\n");
	printf("\n\n* trying to unset %s\n", VARIABLE);
	env_unset(VARIABLE);
	assert(env_get(VARIABLE) == NULL);
	printf("===> unset success\n");
	printf("\n\n* trying to set %s to %s\n", USR_VARIABLE, USR_VALUE);
	env_set(ft_strdup(USR_VARIABLE), ft_strdup(USR_VALUE));
	assert(\
	!ft_strncmp(env_get(USR_VARIABLE), USR_VALUE, ft_strlen(USR_VALUE) + 1));
	printf("===> set success\n");
	hash_table_flush(table);
}
