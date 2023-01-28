/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_manager_bonus.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 00:41:04 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:17:01 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_MANAGER_BONUS_H
# define HEREDOC_MANAGER_BONUS_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "s_tree_node_bonus.h"

/*-------------- FUNCTION PROTOTYPES -------------*/

void	heredoc_init(t_node *root);
int		heredoc_stat_get(void);
void	heredoc_interupted(char *cur_heredoc_file);

#endif