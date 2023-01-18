/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:52:11 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 23:52:22 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	print_syntax_error_message(int token_type, char *token_str)
{
	static char	*type_str[11] = {"newline", 0, "(", ")", "&&", "||", \
								"|", "<", ">", "<<", ">>"};

	printf("goldsh: syntax error near unexpected token ");
	if (token_type == TOKEN_WORD)
		printf("'%s'\n", token_str);
	else
		printf("'%s'\n", type_str[token_type]);
}

void	exit_by_error(char *msg)
{
	ft_putstr_fd("\nError: ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
