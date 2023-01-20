/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 02:19:54 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/21 01:24:26 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include "env_manager.h"

extern char	**environ;

void	show_hash_table(t_hash_table *table);
int		builtin_env(char *argv[]);



void	leak_check(void)
{
	printf("\n\n* check leaks!\n");
	system("leaks expand_test");
}

void	execute_builtin_env(char **argvs)
{
	int	res;

	printf("\n>> EXECUTING env....\n");
	res = builtin_env(argvs);
	if (res == 0)
		printf(">>>> builtin env : !! SUCCESS !!\n");
	else
		printf(">>>> builtin env : !! FAIL !!\n");
}


int	main(void)
{
	t_env_tab	*table;
	char		*line;
	int			arg_cnt;
	char		**argvs;
	int			i;

#ifndef FSANITIZE_FLAG
	atexit(leak_check);
#endif
	table = init_env_table(environ);
	printf("enter the number of arguments\n");
	scanf("%d", &arg_cnt);
	argvs = malloc(sizeof(char *) * (arg_cnt + 2));
	argvs[0] = ft_strdup("env");
	i = 0;
	while (i < arg_cnt)
	{
		argvs[i + 1] = malloc(sizeof(char) * 20);
		scanf("%s", argvs[i + 1]);
		i++;
	}
	argvs[arg_cnt + 1] = NULL;
	execute_builtin_env(argvs);
	printf("\ndone\n");
	hash_table_flush(table);
	show_hash_table(table);
	table = NULL;
}
