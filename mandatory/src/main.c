/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:49:08 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 15:39:07 by hyeyukim         ###   ########.fr       */
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

int	main(int argc, char **argv, char *envp[])
{
	char		*line;

	argc++;
	argv++;
	init_env_table(envp);
	set_signal();
	print_welcome();
	while (1)
	{
		line = readline(PS1_DOLLAR);
		g_goldsh.token = lexer(line);
		g_goldsh.node = parser(g_goldsh.token);
		show_tree(g_goldsh.node, 0);
		destroy_tree(g_goldsh.node);
		// sleep(2);
		// system("leaks minishell");
		free(line);
	}
}
