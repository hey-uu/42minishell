/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:24:36 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 13:56:51 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "prompt.h"
#include "libft.h"
#include "color.h"

void	get_cmd_line(t_prompt type)
{
	static char	*prompt[2] = {PS1_DOLLAR, PS2_REDIR};

	printf("%s", prompt[type]);
}

void	print_welcome(void)
{
	static char	*shell_name = \
" ██████╗  ██████╗ ██╗     ██████╗     ██████╗  █████╗ ██████╗ ██╗   ██╗\n\
██╔════╝ ██╔═══██╗██║     ██╔══██╗    ██╔══██╗██╔══██╗██╔══██╗╚██╗ ██╔╝\n\
██║  ███╗██║   ██║██║     ██║  ██║    ██████╔╝███████║██████╔╝ ╚████╔╝ \n\
██║   ██║██║   ██║██║     ██║  ██║    ██╔══██╗██╔══██║██╔══██╗  ╚██╔╝  \n\
╚██████╔╝╚██████╔╝███████╗██████╔╝    ██████╔╝██║  ██║██████╔╝   ██║   \n\
 ╚═════╝  ╚═════╝ ╚══════╝╚═════╝     ╚═════╝ ╚═╝  ╚═╝╚═════╝    ╚═╝   \n\n";
	static char	*shell_introduction = \
"\n /\\                                                                /\\\
\n    ==============================================================\
\n      welcome to yonazang and meyunkim's shell....\
\n      this is crazy...\
\n      let me introduce my baby... my gold baby.... GEUMJJOKI...\
\n    ==============================================================\
\n";

	printf(YELLO "\n%s" RESET, shell_name);
	printf(ITAL "%s\n" RESET, shell_introduction);
}
