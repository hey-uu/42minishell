/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:48:21 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 13:22:01 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "s_token.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

# define ERR_MSG_NONE NULL
# define ERR_MSG_IN_SYNTAX "syntax error near unexpected token"
# define ERR_MSG_NOT_SET "not set"
# define ERR_MSG_EXECUTE_FAILED "execute failed"
# define ERR_MSG_TOO_MANY_ARGUMENTS "too many arguments"
# define ERR_MSG_NOT_NUMBER "numeric argument required"
# define ERR_MSG_NO_SUCH_FILE_OR_DIR "no such file or directory"
# define ERR_MSG_PERMISSION_DENIED "permission denied"
# define ERR_MSG_INVALID_IDENTIFIER "not a valid identifier"
# define ERR_MSG_IS_A_DIR "is a directory"
# define ERR_MSG_COMMAND_NOT_FOUND "command not found"
# define BUILTIN_ERROR_NUMBER 8

enum e_error_code
{
	NONE_ERROR = 0,
	ERROR_MALLOC_FAILED = 1,
	ERROR_IN_SYNTAX = 2,
	ERROR_EXECUTE_FAILED = 3,
};

enum e_builtin_error_code
{
	ERR_B_NONE,
	ERR_B_NOT_SET,
	ERR_B_EXECUTE_FAILED,
	ERR_B_TOO_MANY_ARGUMENTS,
	ERR_B_NOT_NUMBER,
	ERR_B_NO_SUCH_FILE_OR_DIR,
	ERR_B_PERMISSION_DENIED,
	ERR_B_INVALID_IDENTIFIER
};

enum e_access_command_error_code
{
	NO_SUCH_FILE_OR_DIR,
	IS_A_DIR,
	PERMISSION_DENIED,
	COMMAND_NOT_FOUND
};

/*------------ DEFINE MACRO CONSTANTS ------------*/

void	handle_syntax_error(t_token token);
void	handle_error(int errcode, t_token syntax_error_near_token);
void	handle_builtin_error(int errcode, char *cmd, char *var);
void	handle_access_command_error(int errcode, char *cmd);

#endif