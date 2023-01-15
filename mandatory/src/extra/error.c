/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:52:11 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/15 23:52:05 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "minishell.h"

void	print_syntax_error_message(t_token token)
{
	static char	*token_type_str[11] = {"newline", 0, "(", ")", "&&", "||", \
								"|", "<", ">", "<<", ">>"};

	printf("goldsh: syntax error near unexpected token ");
	if (token.type == TOKEN_WORD)
		printf("'%s'\n", token.str);
	else
		printf("'%s'\n", token_type_str[token.type]);
}

void	handle_error(int errcode, t_token syntax_error_near_token)
{
	if (errcode == 0)
		return ;
	else if (errcode == ERROR_IN_SYNTAX)
		print_syntax_error_message(syntax_error_near_token);
	dprintf(2, "Error! This errorcode is... %d\n", errcode);
	exit(1);
}

void	exit_by_error(char *msg)
{
	ft_putstr_fd("\nError: ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
