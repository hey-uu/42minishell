/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:42:55 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 03:37:35 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_INTERNAL_H
# define HEREDOC_INTERNAL_H

/*--------------- STANDARD HEADERS ---------------*/

# include <unistd.h>
# include <stdlib.h>

/*-------------- USER DEFINED HEADERS ------------*/

# include "libft.h"
# include "constants.h"
# include "env_manager.h"
# include "exit_stat_manager.h"
# include "heredoc_manager.h"
# include "expansion.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

# define CHARSET 				"abcdefghijklmnopqrstuvwxyz\
										ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"
# define INITIAL_TEMP_FILENAME	"/tmp/goldsh_"
# define PS_HEREDOC 			"> "

/*-------------- FUNCTION PROTOTYPES -------------*/

int		get_delimiter_len(char *word);
void	get_delimiter(char **delimiter, int *quote, int dlen, char *word);
void	make_heredoc_with_expansion(char *line, int fd);

// heredoc manager
void	heredoc_interupted(char *cur_heredoc_file);

#endif