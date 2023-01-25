/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:49:08 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 10:00:13 by hyeyukim         ###   ########.fr       */
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

void	free_allocated_memory(t_token *token_list, t_node *parse_tree)
{
	destroy_token_list(token_list);
	destroy_tree(parse_tree);
}

void	run_input_commands(char *input)
{
	t_token	*token_list;
	t_node	*parse_tree;
	int		errcode;
	t_token	syntax_error_near_token;

	errcode = 0;
	lexer(input, &token_list, &errcode, &syntax_error_near_token);
	// if (errcode == 0)
		parser(token_list, &parse_tree, &errcode, &syntax_error_near_token);
	// if (errcode == 0)
		executor(parse_tree, &errcode);
	handle_error(errcode, syntax_error_near_token);
	free_allocated_memory(token_list, parse_tree);
}

int	main(int argc, char **argv, char *envp[])
{
	char	*input;

	argc++;
	argv++;
	// set_signal();
	init_env_table(envp);
	print_welcome();
	while (1)
	{
		input = readline(PS1_DOLLAR);
		add_history(input);
		run_input_commands(input);
		free(input);
	}
}
