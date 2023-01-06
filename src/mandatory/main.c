/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:49:08 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/06 16:02:32 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"
#include "prompt.h"
#include <readline/readline.h>
#include <readline/history.h>

t_goldsh	g_goldsh;

int	main(int argc, char **argv, char **envp)
{
	char	*lists_of_commands;

	argc = 0;
	argv = 0;
	print_welcome();
	while (1)
	{
		lists_of_commands = readline(PS1_DOLLAR);
		update_history();
		wait_signal();
		lexer(lists_of_commands, envp);
		parser();
		executor();
		free(cmd_line);
	}
}
