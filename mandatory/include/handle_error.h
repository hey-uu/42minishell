/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:49:52 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 02:40:30 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_ERROR_H
# define HANDLE_ERROR_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "s_token.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

# define ERR_MSG_NONE NULL
# define ERR_MSG_IN_SYNTAX 					"Syntax error near unexpected token"
# define ERR_MSG_NOT_SET 					"Not set"
# define ERR_MSG_EXECUTE_FAILED 			"Execute failed"
# define ERR_MSG_TOO_MANY_ARGUMENTS 		"Too many arguments"
# define ERR_MSG_NOT_NUMBER 				"Numeric argument required"
# define ERR_MSG_NO_SUCH_FILE_OR_DIR 		"No such file or directory"
# define ERR_MSG_PERMISSION_DENIED 			"Permission denied"
# define ERR_MSG_INVALID_IDENTIFIER 		"Not a valid identifier"
# define ERR_MSG_IS_A_DIR 					"Is a directory"
# define ERR_MSG_COMMAND_NOT_FOUND 			"Command not found"
# define ERR_MSG_AMBIGUOUS_REDIRECT			"Ambiguous redirect"
# define ERR_MSG_SYSCALL_FAILED 			"System call failed"

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

enum e_execute_error_code
{
	ERR_EXE_NONE,
	ERR_EXE_SYSCALL_FAILED,
	ERR_EXE_AMBIGUOUS_REDIR,
	ERR_EXE_NO_SUCH_FILE_OR_DIR
};

/*-------------- FUNCTION PROTOTYPES -------------*/

void	handle_syntax_error(t_token token);
void	handle_error(int errcode, t_token syntax_error_near_token);
void	handle_builtin_error(int errcode, char *cmd, char *var);
void	handle_access_command_error(int errcode, char *cmd);
void	handle_execute_error(int errcode, char *cmd, char *arg);

#endif