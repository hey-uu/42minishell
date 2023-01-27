/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:05:14 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/28 03:28:58 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_SIGNAL_H
# define HANDLE_SIGNAL_H

/*--------------- STANDARD HEADERS ---------------*/

# include <signal.h>

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum e_signal_handle_type {
	DEFAULT,
	IGNORE,
	CATCH
};

/*-------------- FUNCTION PROTOTYPES -------------*/

void	set_signal(int sig_int, int sig_quit);

#endif
