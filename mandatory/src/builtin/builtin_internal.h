/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:14:55 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 18:13:23 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_INTERNAL_H
# define BUILTIN_INTERNAL_H

# include <stdlib.h>
# include <unistd.h>

# include "libft.h"
# include "libprintf.h"
# include "handle_error.h"
# include "env_manager.h"
# include "exit_stat_manager.h"
# include "constants.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

# define VAR_HOME "HOME"
# define VAR_PWD "PWD"
# define VAR_OLDPWD "OLDPWD"

# define CMD_CD "cd"
# define CMD_ECHO "echo"
# define CMD_ENV "env"
# define CMD_EXIT "exit"
# define CMD_EXPORT "export"
# define CMD_UNSET "unset"
# define CMD_PWD "pwd"

enum e_printf_success
{
	PRINTF_SUCCESS,
	PRINTF_FAIL
};

enum e_access_success
{
	ACCESS_SUCCESS,
	ACCESS_FAIL
};

enum e_builtin_success
{
	BUILTIN_SUCCESS = 0,
	BUILTIN_FAIL = -1
};

/*-------------- FUNCTION PROTOTYPES -------------*/

void	builtin_pwd(char *argv[]);
void	free_strs_array(char ***array);
char	*ft_strndup(char *str, int n);
int		is_valid_variable_name_character(char c, int i);

// builtin_cd_internal
int		cd_directory_argument(char *cur_dir, char *new_dir);
void	cd_no_argument(char *cur_dir);
void	cd_hyphen_minus(char *cur_dir);

#endif
