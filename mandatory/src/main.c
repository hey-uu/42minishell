/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:49:08 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 15:59:32 by yeonhkim         ###   ########.fr       */
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
	// set_signal();
	print_welcome();
	while (1)
	{
		line = readline(PS1_DOLLAR);
		// g_goldsh.token = lexer(line);
		// g_goldsh.node = parser(g_goldsh.token);
		free(line);
	}
}
