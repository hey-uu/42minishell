/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_with_expansion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:40:13 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 12:06:15 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "env_manager.h"
#include "expansion.h"

static int	expand_variable_in_heredoc(char *line, int fd)
{
	char	*variable;
	char	*value;
	int		idx;
	int		question_mark;

	idx = 1;
	variable = split_variable(&line[idx], &idx, &question_mark);
	if (!variable && question_mark == VAR_IS_NOT_QMARK)
		return (idx);
	if (question_mark == VAR_IS_QMARK)
		value = exit_stat_get_str();
	else
		value = env_get(variable);
	if (value)
		write(fd, value, ft_strlen(value));
	if (question_mark == VAR_IS_QMARK)
		free(value);
	free(variable);
	return (idx);
}

void	make_heredoc_with_expansion(char *line, int fd)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (line[i])
	{
		if (line[i] == '$' && (line[i + 1] && line[i + 1] != '$' && \
							line[i + 1] != '\'' && line[i + 1] != '\"'))
		{
			write(fd, line + i - len, len);
			i += expand_variable_in_heredoc(&line[i], fd);
			len = 0;
		}
		i++;
		len++;
	}
	if (len)
		write(fd, line + i - len, len);
}
