/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_table_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:13:43 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/15 00:26:51 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>
#include "env_manager.h"
#define VARIABLE "PATH"
#define USR_VARIABLE "hyeyun"
#define USR_VALUE "please... help..."
void	show_hash_table(t_hash_table *table);

int	main(int argc, char **argv, char **envp)
{
	t_env_tab	*table;
	char		*value;

	argc++;
	argv++;
	initialize_env_table(&table, envp);
	show_hash_table(table);
	printf("\n\n* trying to get value of %s\n", VARIABLE);
	value = env_get(table, VARIABLE);
	printf("%s : %s\n", VARIABLE, value);
	printf("===> get success\n");
	printf("\n\n* trying to unset %s\n", VARIABLE);
	env_unset(table, VARIABLE);
	assert(env_get(table, VARIABLE) == NULL);
	printf("===> unset success\n");
	printf("\n\n* trying to set %s to %s\n", USR_VARIABLE, USR_VALUE);
	env_set(table, ft_strdup(USR_VARIABLE), ft_strdup(USR_VALUE));
	assert(\
	!ft_strncmp(env_get(table, USR_VARIABLE), USR_VALUE, ft_strlen(USR_VALUE) + 1));
	printf("===> set success\n");
	hash_table_destroy(table);
}
