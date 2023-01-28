/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 02:19:54 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 15:39:43 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include "env_manager.h"

extern char	**environ;

void	show_hash_table(t_hash_table *table);
int		builtin_exit(char *argv[]);
void	free_str_array(char ***array);


void	leak_check(void)
{
	printf("* check leaks!\n");
	system("leaks expand_test");
}

void	fill_arguments(char ***argvs, int exit_num)
{
	int	i;

	(*argvs) = malloc(sizeof(char *) * 3);
	i = 0;
	while (i < 3)
	{
		(*argvs)[i] = malloc(sizeof(char) * 20);
		i++;
	}
	(*argvs)[0] = ft_strdup("exit");
	if (exit_num == -1)
		(*argvs)[1] = NULL;
	else
		(*argvs)[1] = ft_itoa(exit_num);
	(*argvs)[2] = NULL;
}

void	execute_builtin_exit(char **argvs)
{
	int	stat;
	int	pid;

	printf("\n>> EXECUTING exit....\n");
	pid = fork();
	if (pid == 0)
	{
		builtin_exit(argvs);
		exit(1);
	}
	if (wait(&stat) != -1)
	{
		if (WIFEXITED(stat))
			printf("the exit status is : %d\n", WEXITSTATUS(stat));
		free_str_array(&argvs);
	}
}


int	main(void)
{
	t_env_tab	*table;
	char		*line;
	int			exit_num;
	char		**argvs;

#ifndef FSANITIZE_FLAG
	atexit(leak_check);
#endif
	table = init_env_table(environ);
	while (1)
	{
		printf("enter the number to pass as exit argument..\n");
		printf("If you don't want to pass any argument to exit, enter -1.\n");
		scanf("%d", &exit_num);
		fill_arguments(&argvs, exit_num);
		execute_builtin_exit(argvs);
		printf("\ndone\n");
		printf("enter the number to update current exit status.\n");
		printf("If you want to exit the program, enter -1\n");
		scanf("%d", &exit_num);
		if (exit_num == -1)
			break ;
		exit_stat_update(exit_num);
	}
	hash_table_flush(table);
	show_hash_table(table);
	table = NULL;
}
