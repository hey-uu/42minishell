/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:49:08 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/06 11:33:36 by hyeyukim         ###   ########.fr       */
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
	char	*cmd_line;

	argc = 0;
	argv = 0;
	print_welcome();
	while (1)
	{
		cmd_line = readline(PS1_DOLLAR);
		update_history();
		wait_signal();
		lexer(cmd_line, envp);
		parser();
		executor();
		free(cmd_line);
	}
}
