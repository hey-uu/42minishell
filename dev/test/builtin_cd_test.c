/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 02:19:54 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/20 18:48:49 by hyeyukim         ###   ########.fr       */
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
int		builtin_cd(char	*argv[]);


void	leak_check(void)
{
	printf("\n\n* check leaks!\n");
	system("leaks expand_test");
}

void	print_current_status(void)
{
	char	*cur_dir;

	printf("\n>> current status\n");
	printf(">>>> $HOME : [%s]\n", env_get("HOME"));
	printf(">>>> $OLDPWD : [%s]\n", env_get("OLDPWD"));
	printf(">>>> $PWD : [%s]\n", env_get("PWD"));
	cur_dir = getcwd(NULL, 0);
	printf(">>>> current directory: [%s]\n", cur_dir);
	free(cur_dir);
}

void	execute_builtin_cd(char **argvs)
{
	int	res;

	printf("\n>> EXECUTING CD....\n");
	res = builtin_cd(argvs);
	if (res == 0)
		printf(">>>> builtin cd : !! SUCCESS !!\n");
	else
		printf(">>>> builtin cd : !! FAIL !!\n");
}

void	ask_whether_unset_variables_or_not(char *variable)
{
	int	answer;

	printf("\n>> Do you want to unset [%s]? (1/0)\n", variable);
	scanf("%d", &answer);
	if (answer == 1)
	{
		env_unset(variable);
		printf(">>>> [%s] now unsetted!\n", variable);
	}
}

int	main(void)
{
	t_env_tab	*table;
	char		*line;
	char		**argvs;

#ifndef FSANITIZE_FLAG
	atexit(leak_check);
#endif
	table = init_env_table(environ);
	while (1)
	{
		printf("\n=======================================\n");
		line = readline("Enter argument for builtin cd > ");
		if (!line)
			break;
		argvs = malloc(sizeof(char *) * 3);
		argvs[0] = ft_strdup("cd");
		if (!line[0])
			argvs[1] = NULL;
		else
			argvs[1] = ft_strdup(line);
		argvs[2] = NULL;
		print_current_status();
		execute_builtin_cd(argvs);
		print_current_status();
		ask_whether_unset_variables_or_not("HOME");
		ask_whether_unset_variables_or_not("PWD");
		ask_whether_unset_variables_or_not("OLDPWD");
		free(line);
		line = NULL;
		argvs = NULL;
		leak_check();
		printf("\n=======================================\n");
	}
	printf("\ndone\n");
	hash_table_flush(table);
	show_hash_table(table);
	table = NULL;
}
