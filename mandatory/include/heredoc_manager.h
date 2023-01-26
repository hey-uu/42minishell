/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_manager.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 00:41:04 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 08:16:27 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_MANAGER_H
# define HEREDOC_MANAGER_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "s_tree_node.h"

/*-------------- FUNCTION PROTOTYPES -------------*/

void	heredoc_init(t_node *root);
int		heredoc_stat_get(void);
void	heredoc_interupted(char *cur_heredoc_file);

#endif