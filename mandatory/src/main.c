/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:49:08 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 20:37:59 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_shell(char *envp[])
{
	init_env_table(envp);
	set_signal(CATCH, CATCH);
	print_welcome();
}

int	main(int argc, char **argv, char *envp[])
{
	char			*input;

	(void)argc;
	(void)argv;
	init_shell(envp);
	while (1)
	{
		input = readline("goldsh $");
		if (!input)
			builtin_exit(NULL);
		add_history(input);
		run_commands(input);
		free(input);
	}
}
