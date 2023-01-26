/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:49:08 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/26 17:57:56 by yeonhkim         ###   ########.fr       */
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
	// struct termios	ori_term;

	init_shell(envp);
	while (1)
	{
		input = readline(PS1_DOLLAR);
		if (!input)
			builtin_exit(NULL);
		add_history(input);
		run_commands(input);
		free(input);
		// system("leaks minishell");
	}
	// set_terminal(CANONICAL);
}
