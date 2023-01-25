/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 08:46:06 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 17:44:34 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal_handle.h"
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

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

static void	signal_ignore(int signo)
{
	printf("\n");
}

void	set_signal(int sig_int, int sig_quit)
{
	{
		if (sig_int == DEFAULT)
			signal(SIGINT, SIG_DFL);
		else if (sig_int == IGNORE)
			signal(SIGINT, signal_ignore);
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