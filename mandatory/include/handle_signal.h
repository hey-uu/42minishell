/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:05:14 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/27 16:21:58 by yeonhkim         ###   ########.fr       */
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
