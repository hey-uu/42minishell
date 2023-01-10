/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:49:08 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/08 20:49:42 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "minishell.h"
#include "prompt.h"
#include <readline/readline.h>
#include <readline/history.h>


// int	main(int argc, char **argv, char **envp)
// {
// 	char	*lists_of_commands;

// 	argc = 0;
// 	argv = 0;
// 	envp = 0;
// 	print_welcome();
// 	// signal 설정
// 	while (1)
// 	{
// 		lists_of_commands = readline(PS1_DOLLAR);
// 		// update_history();
// 		// lexer(lists_of_commands, envp);
// 		// parser();
// 		// executor();
// 		free(lists_of_commands);
// 	}
// }
