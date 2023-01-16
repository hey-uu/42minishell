/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:49:08 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 17:05:44 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"
#include "prompt.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "env_manager.h"

// 처리해야할 것
// * signal 설정
// * history 업데이트
// * executor 함수

int	main(int argc, char **argv, char **envp)
{
	char		*lists_of_commands;
	t_env_tab	*env_table;

	argc++;
	argv++;
	envp++;
	initialize_env_table(&env_table, envp);
	print_welcome();
	while (1)
	{
		lists_of_commands = readline(PS1_DOLLAR);
		g_goldsh.token = lexer(lists_of_commands);
		g_goldsh.node = parser(g_goldsh.token);
		show_tree(g_goldsh.node, 0);
		destroy_tree(g_goldsh.node);
		// sleep(2);
		// system("leaks minishell");
		free(lists_of_commands);
	}
}
