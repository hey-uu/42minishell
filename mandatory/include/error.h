/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:48:21 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 23:48:06 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "minishell.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/
void	print_syntax_error_message(int token_type, char *token_str);

#endif