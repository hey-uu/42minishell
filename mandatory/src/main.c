/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:49:08 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 17:50:45 by yeonhkim         ###   ########.fr       */
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
#include "executor.h"
#include "signal_handle.h"

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
	if (errcode == 0)
		parser(token_list, &parse_tree, &errcode, &syntax_error_near_token);
	if (errcode == 0)
		executor(parse_tree, &errcode);
	handle_error(errcode, syntax_error_near_token);
	free_allocated_memory(token_list, parse_tree);
}

// #include <termios.h>

// enum e_termios {
// 	ORI,
// 	DEF
// };

// enum e_terminal_set {
// 	CANONICAL,	
// 	NON_CANONICAL
// };

// void	set_terminal(int input_mode)
// {
// 	static struct termios	ori_term;
// 	static struct termios	def_term;
// 	static int				called;

// 	if (!called)
// 	{
// 		tcgetattr(STDIN_FILENO, &ori_term);
// 		def_term.c_lflag &= ~(ICANON | ECHO);
// 		def_term.c_cc[VMIN] = 1; 
// 		def_term.c_cc[VTIME] = 0;
// 		called = 1;
// 	}
// 	if (input_mode == CANONICAL)
// 		tcsetattr(STDIN_FILENO, TCSANOW, &ori_term);
// 	else
// 		tcsetattr(STDIN_FILENO, TCSANOW, &def_term);
// }

void	init_shell(char *envp[])
{
	print_welcome();
	set_signal(CATCH, CATCH);
	// set_terminal(NON_CANONICAL);
	init_env_table(envp);
}

int	main(int argc, char **argv, char *envp[])
{
	char			*input;
	struct termios	ori_term;

	init_shell(envp);
	while (1)
	{
		input = readline(PS1_DOLLAR);
		if (!input)
			builtin_exit(NULL);
		add_history(input);
		run_input_commands(input);
		free(input);
	}
	// set_terminal(CANONICAL);
}
