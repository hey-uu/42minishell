/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:24:08 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/21 09:29:18 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin_internal.h"
#include "env_manager.h"
#include "error.h"
#include "libft.h"

static int	__export_print_marked_variable_list__(char ***argv)
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

static int	__is_valid_character_for_variable_name__(char c, int i)
{
	if (i == 0 && !(ft_isalpha(c) || c == '_'))
		return (0);
	if (!(ft_isalnum(c) || c == '_'))
		return (0);
	return (1);
}

static void	__export_append_variable_value__(char *line, int i)
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

static int	__export_update_marked_variable__(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] != '+' && line[i] != '='))
	{
		if (!__is_valid_character_for_variable_name__(line[i], i))
		{
			print_error_message(ERROR_INVALID_IDENTIFIER, BUILTIN_EXPORT, line);
			return (BUILTIN_FAIL);
		}
		i++;
	}
	if (line[i] == '+' && line[i + 1] != '=')
	{
		print_error_message(ERROR_INVALID_IDENTIFIER, BUILTIN_EXPORT, line);
		return (BUILTIN_FAIL);
	}
	else if (line[i] == '+')
		__export_append_variable_value__(line, i);
	else if (line[i] == '=')
		env_set(ft_strndup(line, i), ft_strdup(&line[i + 1]));
	else
		env_set(ft_strndup(line, i), NULL);
	return (BUILTIN_SUCCESS);
}

int	builtin_export(char **argv)
{
	int	res;
	int	i;

	if (!argv[1])
		return (__export_print_marked_variable_list__(&argv));
	res = BUILTIN_SUCCESS;
	i = 0;
	while (argv[i])
	{
		if (__export_update_marked_variable__(argv[i]) == BUILTIN_FAIL)
			res = BUILTIN_FAIL;
		free(argv[i]);
		i++;
	}
	free(argv);
	return (res);
}
