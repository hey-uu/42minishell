/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:24:08 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 02:16:02 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin_internal.h"
#include "env_manager.h"
#include "error.h"
#include "libft.h"

static int	export_print_marked_variable_list(char ***argv)
{
	char	**variable_list;
	int		i;

	free_double_char_array(argv);
	variable_list = env_get_marked_variable_list();
	i = 0;
	while (variable_list[i])
	{
		printf("declare -x %s\n", variable_list[i]);
		free(variable_list[i]);
		i++;
	}
	free(variable_list);
	return (BUILTIN_SUCCESS);
}

static void	export_append_variable_value(char *line, int i)
{
	char	*variable;
	char	*old_value;
	char	*appending_value;
	char	*new_value;

	variable = ft_strndup(line, i);
	old_value = env_get(variable);
	appending_value = ft_strdup(&line[i + 2]);
	if (!old_value)
		new_value = appending_value;
	else
	{
		new_value = ft_strjoin(old_value, appending_value);
		free(appending_value);
	}
	env_set(variable, new_value);
}

int	export_update_marked_variable(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] != '+' && line[i] != '='))
	{
		if (!is_valid_variable_name_character(line[i], i))
		{
			print_builtin_error_message(\
			BERR_INVALID_IDENTIFIER, CMD_EXPORT, line);
			return (BUILTIN_FAIL);
		}
		i++;
	}
	if (line[i] == '+' && line[i + 1] != '=')
	{
		print_builtin_error_message(BERR_INVALID_IDENTIFIER, CMD_EXPORT, line);
		return (BUILTIN_FAIL);
	}
	else if (line[i] == '+')
		export_append_variable_value(line, i);
	else if (line[i] == '=')
		env_set(ft_strndup(line, i), ft_strdup(&line[i + 1]));
	else
		env_set(ft_strndup(line, i), NULL);
	return (BUILTIN_SUCCESS);
}

void	builtin_export(char *argv[])
{
	int	i;

	if (!argv[1])
	{
		export_print_marked_variable_list(&argv);
		return ;
	}
	i = 0;
	while (argv[i])
	{
		if (export_update_marked_variable(argv[i]) == BUILTIN_FAIL)
			exit_stat_update(1);
		free(argv[i]);
		i++;
	}
	free(argv);
}
