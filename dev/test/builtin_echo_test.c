/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:47:52 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 15:39:43 by yeonhkim         ###   ########.fr       */
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

int		builtin_echo(char	*argv[]);
void	free_str_array(char ***array);


void	leak_check(void)
{
	printf("\n\n* check leaks!\n");
	system("leaks expand_test");
}

void	execute_builtin_echo(char **argvs)
{
	int	res;

	printf("\n>> EXECUTING ECHO....\n");
	printf(">>>> result\n");
	res = builtin_echo(argvs);
	if (res == 0)
		printf(">>>>>> builtin echo : !! SUCCESS !!\n");
	else
		printf(">>>>>> builtin echo : !! FAIL !!\n");
}

int	main(void)
{
	char	**argvs;
	int		arg_num;
	int		i;

#ifndef FSANITIZE_FLAG
	atexit(leak_check);
#endif
	while (1)
	{
		printf("\n=======================================\n");
		printf("Enter the number of arguments\n");
		scanf("%d", &arg_num);
		if (!arg_num)
			break ;
		argvs = malloc(sizeof(char *) * (arg_num + 2));
		argvs[0] = ft_strdup("echo");
		argvs[arg_num + 1] = NULL;
		for (i = 0 ; i < arg_num; i++)
		{
			argvs[i + 1] = malloc(sizeof(char) * 30);
			scanf("%s", argvs[i + 1]);
		}
		execute_builtin_echo(argvs);
		argvs = NULL;
		leak_check();
		printf("\n=======================================\n");
	}
	printf("\ndone\n");
}
