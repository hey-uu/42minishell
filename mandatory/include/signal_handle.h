/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handle.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:05:14 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/25 22:15:34 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLE_H
# define SIGNAL_HANDLE_H

# include <signal.h>

# define IGNORE 1
# define DEFAULT 2
# define CATCH 3

void	set_signal(int sig_int, int sig_quit);

#endif
