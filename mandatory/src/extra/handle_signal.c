/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 08:46:06 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 19:45:13 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <readline/history.h>
#include <readline/readline.h>
#include "handle_signal.h"

static void	print_newline(int signo)
{
	(void)signo;
	write(1, "\n", 1);
}

static void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (signo == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	set_signal(int sig_int, int sig_quit)
{
	{
		if (sig_int == DEFAULT)
			signal(SIGINT, SIG_DFL);
		else if (sig_int == IGNORE)
			signal(SIGINT, print_newline);
		else if (sig_int == CATCH)
			signal(SIGINT, signal_handler);
	}
	{
		if (sig_quit == DEFAULT)
			signal(SIGQUIT, SIG_DFL);
		else if (sig_quit == IGNORE)
			signal(SIGQUIT, SIG_IGN);
		else if (sig_quit == CATCH)
			signal(SIGQUIT, signal_handler);
	}
}
