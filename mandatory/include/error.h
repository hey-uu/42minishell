/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:48:21 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/19 21:05:57 by yeonhkim         ###   ########.fr       */
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
	ERROR_EXECUTE_FAILED = 3
};

/*------------ DEFINE MACRO CONSTANTS ------------*/

void	print_syntax_error_message(t_token token);
void	handle_error(int errcode, t_token syntax_error_near_token);

#endif