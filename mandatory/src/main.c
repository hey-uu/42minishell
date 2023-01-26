/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:49:08 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/26 20:43:53 by yeonhkim         ###   ########.fr       */
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

void	init_shell(char *envp[])
{
	print_welcome();
	set_signal(CATCH, CATCH);
	init_env_table(envp);
}

int	main(int argc, char **argv, char *envp[])
{
	char			*input;

	argc = 0;
	argv = NULL;
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
}
