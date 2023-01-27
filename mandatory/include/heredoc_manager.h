/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_manager.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 00:41:04 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 02:42:02 by yona             ###   ########.fr       */
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