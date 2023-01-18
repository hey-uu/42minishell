/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:49:08 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 17:23:40 by yeonhkim         ###   ########.fr       */
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

// void	free_allocated_memory(char)
// {
// 	destroy_token_list(token_list);
// 	destroy_tree(parse_tree);
// }

void	run_input_commands(char *input)
{
	t_token	*token_list;
	t_node	*parse_tree;

	token_list = lexer(input);
	parse_tree = parser(token_list);
	executor(parse_tree);
	// lexer(input, &token_list);
	// parser(token_list, &parse_tree);
	// executor(parse_tree);
}

int	main(int argc, char **argv, char *envp[])
{
	char	*input;

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