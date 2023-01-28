/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:49:39 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:16:32 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_BONUS_H
# define CONSTANTS_BONUS_H

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