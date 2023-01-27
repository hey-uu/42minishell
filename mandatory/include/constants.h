/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:49:39 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 02:43:44 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

/*------------ DEFINE MACRO CONSTANTS ------------*/

enum e_result_status
{
	FAILURE = -1,
	SUCCESS = 0
};

enum e_bool
{
	FALSE = 0,
	TRUE = 1
};

enum	e_heredoc_stat
{
	HEREDOC_NONE,
	HEREDOC_INTSIG
};

#endif