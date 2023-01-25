/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:24:08 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 13:02:14 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin_internal.h"
#include "env_manager.h"
#include "error.h"
#include "libft.h"

static void	export_print_marked_variable_list(char ***argv)
{
	char	**variable_list;
	int		i;

	free_double_char_array(argv);
	variable_list = env_get_marked_variable_list();
	i = 0;
	while (variable_list[i])
	{
		if (printf("declare -x %s\n", variable_list[i]) < 0)
		{
			handle_builtin_error(ERR_B_EXECUTE_FAILED, CMD_EXPORT, "printf");
			free_double_char_array(&variable_list);
			return ;
		}
		i++;
	}
	free_double_char_array(&variable_list);
	exit_stat_update(0);
}

static void	export_append_variable_value(char *arg, int i)
{
	char	*variable;
	char	*old_value;
	char	*appending_value;
	char	*new_value;

	variable = ft_strndup(arg, i);
	old_value = env_get(variable);
	appending_value = ft_strdup(&arg[i + 2]);
	if (!old_value)
		new_value = appending_value;
	else
	{
		new_value = ft_strjoin(old_value, appending_value);
		free(appending_value);
	}
	env_set(variable, new_value);
}

static int	export_update_marked_variable(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] && (arg[i] != '+' && arg[i] != '='))
	{
		if (!is_valid_variable_name_character(arg[i], i))
		{
			handle_builtin_error(ERR_B_INVALID_IDENTIFIER, CMD_EXPORT, arg);
			return (BUILTIN_FAIL);
		}
		i++;
	}
	if (arg[i] == '+' && arg[i + 1] != '=')
	{
		handle_builtin_error(ERR_B_INVALID_IDENTIFIER, CMD_EXPORT, arg);
		return (BUILTIN_FAIL);
	}
	else if (arg[i] == '+')
		export_append_variable_value(arg, i);
	else if (arg[i] == '=')
		env_set(ft_strndup(arg, i), ft_strdup(&arg[i + 1]));
	else
		env_set(ft_strndup(arg, i), NULL);
	return (BUILTIN_SUCCESS);
}

void	builtin_export(char *argv[])
{
	int	i;
	int	res;

	if (!argv[1])
	{
		export_print_marked_variable_list(&argv);
		return ;
	}
	free(argv[0]);
	res = BUILTIN_SUCCESS;
	i = 1;
	while (argv[i])
	{
		if (export_update_marked_variable(argv[i]) == BUILTIN_FAIL)
			res = BUILTIN_FAIL;
		free(argv[i]);
		i++;
	}
	free(argv);
	if (res == BUILTIN_SUCCESS)
		exit_stat_update(0);
}
