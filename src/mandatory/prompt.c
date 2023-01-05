/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:24:36 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/06 03:18:48 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "prompt.h"
#include "libft.h"

void	print_prompt(t_prompt type)
{
	static char	*prompt[2] = {"goldsh $ ", "> "};

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

	printf("\
\n%s\
\n ^                                                                ^\
\n   ==============================================================\
\n     welcome to yonazzang and meyunkim's shell....\
\n     this is crazy...\
\n     let me introduce my baby... my gold baby.... GEUMJJOKI...\
\n   ==============================================================\
\n\n", shell_name);

}
