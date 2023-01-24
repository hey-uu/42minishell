/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:48:21 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 06:37:19 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "s_token.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum e_error_code
{
	NONE_ERROR = 0,
	ERROR_MALLOC_FAILED = 1,
	ERROR_IN_SYNTAX = 2,
	ERROR_EXECUTE_FAILED = 3,
};

enum e_builtin_error_code
{
	BERR_ENV_UNSET,
	BERR_EXECUTE_FAILED,
	BERR_TOO_MANY_ARGUMENTS,
	BERR_NOT_NUMBER,
	BERR_NON_EXISTENT,
	BERR_PERMISSION_DENIED,
	BERR_INVALID_IDENTIFIER
};

enum e_access_command_error_code
{
	NO_SUCH_FILE_OR_DIR,
	IS_A_DIR,
	PERMISSION_DENIED,
	COMMAND_NOT_FOUND
};


/*------------ DEFINE MACRO CONSTANTS ------------*/

void	print_syntax_error_message(t_token token);
void	handle_error(int errcode, t_token syntax_error_near_token);
void	print_builtin_error_message(int error_number, char *cmd, char *var);
void	handle_access_command_error(int errcode, char *cmd);

#endif