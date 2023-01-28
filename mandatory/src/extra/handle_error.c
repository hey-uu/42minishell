/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:52:11 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 18:43:00 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "handle_error.h"
#include "exit_stat_manager.h"

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
	const char	*token_type_str[11] = {
		"'newline'", NULL, "'('", "')'", "'&&'",
		"'||'", "'|'", "'<'", "'>'", "'<<'", "'>>'"
	};

	if (token.type == TOKEN_WORD)
		error_print(NULL, NULL, ERR_MSG_IN_SYNTAX, token.str);
	else
		error_print(NULL, NULL, ERR_MSG_IN_SYNTAX, token_type_str[token.type]);
	exit_stat_update(258);
}

void	handle_builtin_error(int errcode, char *cmd, char *arg)
{
	const char	*msg[] = {
		ERR_MSG_NONE,
		ERR_MSG_NOT_SET,
		ERR_MSG_EXECUTE_FAILED,
		ERR_MSG_TOO_MANY_ARGUMENTS,
		ERR_MSG_NOT_NUMBER,
		ERR_MSG_NO_SUCH_FILE_OR_DIR,
		ERR_MSG_PERMISSION_DENIED,
		ERR_MSG_INVALID_IDENTIFIER
	};
	const int	exit_stat[] = {0, 1, 1, 1, 255, 1, 1, 1};

	error_print(cmd, arg, msg[errcode], NULL);
	exit_stat_update(exit_stat[errcode]);
}

void	handle_access_command_error(int errcode, char *cmd)
{
	const char	*msg[] = {
		ERR_MSG_NO_SUCH_FILE_OR_DIR,
		ERR_MSG_IS_A_DIR,
		ERR_MSG_PERMISSION_DENIED,
		ERR_MSG_COMMAND_NOT_FOUND
	};
	const int	exit_stat[] = {
		127, 126, 126, 127
	};

	error_print(cmd, NULL, msg[errcode], NULL);
	exit_stat_update(exit_stat[errcode]);
}

void	handle_execute_error(int errcode, char *cmd, char *arg)
{
	const char	*msg[] = {
		ERR_MSG_NONE,
		ERR_MSG_SYSCALL_FAILED,
		ERR_MSG_AMBIGUOUS_REDIRECT,
		ERR_MSG_NO_SUCH_FILE_OR_DIR
	};
	const int	exit_stat[] = {
		0, 1, 1, 1
	};

	error_print(cmd, arg, msg[errcode], NULL);
	exit_stat_update(exit_stat[errcode]);
}
