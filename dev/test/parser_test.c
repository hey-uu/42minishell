/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:39:37 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/12 22:13:18 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"
#include "prompt.h"
#include <readline/readline.h>
#include <readline/history.h>
#include "test.h"
#include "tree.h"


int	main(int argc, char **argv, char **envp)
{
	char	*lists_of_commands;

	argc = 0;
	argv = 0;
	envp = 0;
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