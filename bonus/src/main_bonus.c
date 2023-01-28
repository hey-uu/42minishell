/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:49:08 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:17:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

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
		input = readline("goldsh $ ");
		if (!input)
			builtin_exit(NULL);
		add_history(input);
		run_commands(input);
		free(input);
	}
}
