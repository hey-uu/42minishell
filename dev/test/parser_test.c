/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:39:37 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 17:51:27 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"
#include "prompt.h"
#include "test.h"
#include "tree.h"
#include "env_manager.h"

int	main(int argc, char **argv, char **envp)
{
	char		*lists_of_commands;
	t_token		*tokens;
	t_tree_node	*parse_tree;

	argc++;
	argv++;
	envp++;
	init_env_table(envp);
	print_welcome();
	while (1)
	{
		lists_of_commands = readline(PS1_DOLLAR);
		lexer(lists_of_commands, &tokens);
		parser(tokens, &parse_tree);
		show_tree(parse_tree, 0);
		destroy_tree(parse_tree);
		// sleep(2);
		// system("leaks minishell");
		free(lists_of_commands);
	}
}
