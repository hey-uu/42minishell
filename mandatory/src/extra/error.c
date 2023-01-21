/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:52:11 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/21 08:49:01 by hyeyukim         ###   ########.fr       */
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

void	print_error_message(int error_number, int cmd, char *arg)
{
	const char	*cmds[6] = {"cd", "echo", "env", "exit", "export", "pwd"};

	if (error_number == ERROR_ENV_UNSET)
		printf("goldsh: %s: %s not set\n", cmds[cmd], arg);
	else if (error_number == ERROR_EXECUTE_FAILED)
		printf("goldsh: %s: %s execute failed.\n", cmds[cmd], arg);
	else if (error_number == ERROR_TOO_MANY_ARGUMENTS)
		printf("goldsh: %s: too many arguments\n", cmds[cmd]);
	else if (error_number == ERROR_NOT_NUMBER)
		printf("goldsh: %s: %s: numeric argument required\n", cmds[cmd], arg);
	else if (error_number == ERROR_NOT_EXIST)
		printf("goldsh: %s: %s: no such file or directory\n", cmds[cmd], arg);
	else if (error_number == ERROR_PERMISSION_DENIED)
		printf("goldsh: %s: %s: permission denied\n", cmds[cmd], arg);
	else if (error_number == ERROR_INVALID_IDENTIFIER)
		printf("goldsh: %s: %s: not a valid identifier\n", cmds[cmd], arg);
	
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
