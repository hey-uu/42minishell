/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:52:11 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 09:58:33 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "minishell.h"
#include "env_manager.h"

void	error_print(\
		const char *cmd, const char *arg1, const char *msg, const char *arg2)
{
	ft_putstr_fd("goldsh: ", STDERR_FILENO);
	if (cmd)
	{
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (arg1)
	{
		ft_putstr_fd(arg1, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd((char *)msg, STDERR_FILENO);
	if (arg2)
	{
		ft_putstr_fd(" ", STDERR_FILENO);
		ft_putstr_fd(arg2, STDERR_FILENO);
	}
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	handle_syntax_error(t_token token)
{
	const char	*token_type_str[11] = {"newline", 0, "'('", "')'", "'&&'", \
								"'||'", "'|'", "'<'", "'>'", "'<<'", "'>>'"};
	const char	*msg = "syntax error near unexpected token";

	if (token.type == TOKEN_WORD)
		error_print(NULL, NULL, msg, token.str);
	else
		error_print(NULL, NULL, msg, token_type_str[token.type]);
	exit_stat_update(258);
}

void	handle_builtin_error(int errcode, char *cmd, char *arg, int exit_stat)
{
	const char	*msg[] = {"not set", \
						"execute failed", \
						"too many arguments", \
						"numeric argument required", \
						"no such file or directory", \
						"permission denied", \
						"not a valid identifier"};

	error_print(cmd, arg, msg[errcode - 1], NULL);
	exit_stat_update(exit_stat);
}

void	handle_access_command_error(int errcode, char *cmd)
{
	if (errcode == NO_SUCH_FILE_OR_DIR)
	{
		error_print(cmd, NULL, "No such file or directory", NULL);
		exit_stat_update(127);
	}
	else if (errcode == IS_A_DIR)
	{
		error_print(cmd, NULL, "is a directory", NULL);
		exit_stat_update(126);
	}
	else if (errcode == PERMISSION_DENIED)
	{
		error_print(cmd, NULL, "Permission denied", NULL);
		exit_stat_update(126);
	}
	else if (errcode == COMMAND_NOT_FOUND)
	{
		error_print(cmd, NULL, "command not found", NULL);
		exit_stat_update(127);
	}
}

void	handle_error(int errcode, t_token syntax_error_near_token)
{
	if (errcode == 0)
		return ;
	else if (errcode == ERROR_IN_SYNTAX)
		handle_syntax_error(syntax_error_near_token);
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
