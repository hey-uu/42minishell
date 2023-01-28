/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 08:46:06 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:55:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <readline/history.h>
#include <readline/readline.h>
#include "handle_signal.h"
#include "exit_stat_manager.h"

static void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		exit_stat_update(1);
	}
	if (signo == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
	return ;
}

void	set_signal(int sig_int, int sig_quit)
{
	{
		if (sig_int == DEFAULT)
			signal(SIGINT, SIG_DFL);
		else if (sig_int == IGNORE)
			signal(SIGINT, SIG_IGN);
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
	return ;
}
