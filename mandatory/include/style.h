/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   style.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:22:05 by yeonhkim          #+#    #+#             */
/*   Updated: 2023/01/28 15:25:41 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STYLE_H
# define STYLE_H

/*------------ DEFINE MACRO CONSTANTS ------------*/

// ANSI Escape codes defines print style

/* font style */
# define RESET		"\x1B[0m"
# define BOLD		"\x1B[1m"
# define FAINT		"\x1B[2m"
# define ITAL		"\x1B[3m"

/* color */
# define RED		"\x1B[31m"
# define GREEN		"\x1B[32m"
# define YELLO		"\x1B[33m"
# define BLUE		"\x1B[34m"
# define MAGENTA	"\x1B[35m"
# define CYAN		"\x1B[36m"

#endif
