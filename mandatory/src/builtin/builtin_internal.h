/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:14:55 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/24 23:42:19 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_INTERNAL_H
# define BUILTIN_INTERNAL_H

/*--------------- STANDARD HEADERS ---------------*/

/*------------ DEFINE MACRO CONSTANTS ------------*/

# define VAR_HOME "HOME"
# define VAR_PWD "PWD"
# define VAR_OLDPWD "OLDPWD"

enum e_builtin_type
{
	BUILTIN_CD,
	BUILTIN_ECHO,
	BUILTIN_ENV,
	BUILTIN_EXIT,
	BUILTIN_EXPORT,
	BUILTIN_PWD
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

/*-------------- USER DEFINED HEADERS ------------*/

/*------------- STRUCT DECLARATIONS --------------*/

/*-------------- FUNCTION PROTOTYPES -------------*/

int		builtin_pwd(char *argv[]);
void	free_double_char_array(char ***array);
char	*ft_strndup(char *str, int n);
int		is_valid_variable_name_character(char c, int i);

// builtin_cd_internal
int		cd_check_access(char *dir);
int		cd_set_pwd_variables(char *oldpwd_dir);
int		cd_directory_argument(char *cur_dir, char *new_dir);
int		cd_no_argument(char *cur_dir);
int		cd_hyphen_minus(char *cur_dir);

#endif