/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:05:14 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/27 18:50:24 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_SIGNAL_H
# define HANDLE_SIGNAL_H

# include <signal.h>

# define IGNORE 1
# define DEFAULT 2
# define CATCH 3

void	set_signal(int sig_int, int sig_quit);

#endif
