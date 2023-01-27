/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:49:08 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 18:47:07 by yeonhkim         ###   ########.fr       */
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
		input = readline(PS1_DOLLAR);
		if (!input)
			exit(1);
			// builtin_exit(NULL);
		add_history(input);
		run_commands(input);
		free(input);
		// system("leaks minishell");
	}
}
