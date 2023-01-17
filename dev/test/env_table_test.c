/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_table_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:13:43 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/17 13:41:24 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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

void	test_env_get(void)
{
	char	*value;

	printf("\n\n* trying to get value of [%s]\n", VARIABLE);
	value = env_get(VARIABLE);
	printf("%s : %s\n", VARIABLE, value);
	printf("\n===> get success\n");
}

void	test_env_unset(void)
{
	printf("\n\n* trying to unset [%s]\n", VARIABLE);
	env_unset(VARIABLE);
	assert(env_get(VARIABLE) == NULL);
	printf("===> unset success\n");
}

void	test_env_set(void)
{
	printf("\n\n* trying to set [%s] to [%s]\n", USR_VARIABLE, USR_VALUE);
	env_set(ft_strdup(USR_VARIABLE), ft_strdup(USR_VALUE));
	assert(\
	!ft_strncmp(env_get(USR_VARIABLE), USR_VALUE, ft_strlen(USR_VALUE) + 1));
	printf("===> set success\n");
}

void	test_exit_manager(void)
{
	char	*value;

	printf("\n\n* trying to get exit stat\n");
	value = exit_stat_get_str();
	printf("%s\n", value);
	assert(value != NULL);
	printf("===> get exit stat success\n\n");
}

void	check(void)
{
	printf("\n\n* check leaks!\n");
	system("leaks env_test");
}

int	main(int argc, char *argv[], char *envp[])
{
	t_env_tab	*table;

	atexit(check);
	argc++;
	argv++;
	table = initialize_env_table(envp);
	show_hash_table(table);
	test_env_get();
	test_env_set();
	test_env_unset();
	test_exit_manager();
	hash_table_flush(table);
}
