/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:42:55 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 18:13:35 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_INTERNAL_H
# define HEREDOC_INTERNAL_H

/*--------------- STANDARD HEADERS ---------------*/

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <readline/readline.h>
# include "constants.h"

/*-------------- USER DEFINED HEADERS ------------*/

# include "libft.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

# define CHARSET "abcdefghijklmnopqrstuvwxyz\
ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"
# define INITIAL_TEMP_FILENAME "/tmp/goldsh_"
# define PS_HEREDOC "> "

/*-------------- FUNCTION PROTOTYPES -------------*/

int		get_delimiter_len(char *word);
void	get_delimiter(char **delimiter, int *quote, int dlen, char *word);
void	make_heredoc_with_expansion(char *line, int fd);

#endif