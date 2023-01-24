/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:52:11 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 07:02:10 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "minishell.h"
#include "env_manager.h"

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

void	error_print(char *cmd, char *arg, const char *msg)
{
	ft_putstr_fd("goldsh: ", STDERR_FILENO);
	if (cmd)
	{
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	if (arg)
	{
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd((char *)msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}

void	print_builtin_error_message(int error_number, char *cmd, char *arg)
{
	const char	*msg[] = {"not set", \
						"execute failed", \
						"too many arguments", \
						"numeric argument required", \
						"no such file or directory", \
						"permission denied", \
						"not a valid identifier"};

	error_print(cmd, arg, msg[error_number]);
}

void	handle_access_command_error(int errcode, char *cmd)
{
	if (errcode == NO_SUCH_FILE_OR_DIR)
	{
		error_print(cmd, NULL, "No such file or directory");
		exit_stat_update(127);
	}
	else if (errcode == IS_A_DIR)
	{
		error_print(cmd, NULL, "is a directory");
		exit_stat_update(126);	
	}
	else if (errcode == PERMISSION_DENIED)
	{
		error_print(cmd, NULL, "Permission denied");
		exit_stat_update(126);	
	}
	else if (errcode == COMMAND_NOT_FOUND)
	{
		error_print(cmd, NULL, "command not found");
		exit_stat_update(127);	
	}
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
