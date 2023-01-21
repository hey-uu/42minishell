/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:48:21 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/21 08:49:01 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/*-------------- USER DEFINED HEADERS ------------*/

#include "s_token.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum e_error_code
{
	NONE_ERROR = 0,
	ERROR_MALLOC_FAILED = 1,
	ERROR_IN_SYNTAX = 2,
	ERROR_EXECUTE_FAILED = 3,
	ERROR_ENV_UNSET,
	ERROR_PERMISSION_DENIED,
	ERROR_NOT_EXIST,
	ERROR_TOO_MANY_ARGUMENTS,
	ERROR_NOT_NUMBER,
	ERROR_INVALID_IDENTIFIER
};

/*------------ DEFINE MACRO CONSTANTS ------------*/

void	print_syntax_error_message(t_token token);
void	handle_error(int errcode, t_token syntax_error_near_token);
void	print_error_message(int error_number, int builtin_cmd, char *var);

#endif