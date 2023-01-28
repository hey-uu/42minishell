/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:14:55 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 18:42:54 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_INTERNAL_H
# define BUILTIN_INTERNAL_H

/*--------------- STANDARD HEADERS ---------------*/

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

/*-------------- USER DEFINED HEADERS ------------*/

# include "libft.h"
# include "constants.h"
# include "str_utils.h"
# include "handle_error.h"
# include "env_manager.h"
# include "exit_stat_manager.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

# define VAR_HOME		"HOME"
# define VAR_PWD		"PWD"
# define VAR_OLDPWD		"OLDPWD"

# define CMD_CD			"cd"
# define CMD_ECHO		"echo"
# define CMD_ENV		"env"
# define CMD_EXIT		"exit"
# define CMD_EXPORT		"export"
# define CMD_UNSET		"unset"
# define CMD_PWD		"pwd"

/*-------------- FUNCTION PROTOTYPES -------------*/

int		is_valid_variable_name_character(char c, int i);

/* utils for cd */
int		cd_directory_argument(char *cur_dir, char *new_dir);
void	cd_no_argument(char *cur_dir);
void	cd_hyphen_minus(char *cur_dir);

#endif
