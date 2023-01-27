/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:49:39 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 20:29:38 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

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