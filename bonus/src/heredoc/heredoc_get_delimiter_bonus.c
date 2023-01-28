/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_get_delimiter_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:38:22 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:18:47 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_delimiter_len(char *word)
{
	int		is_quote;
	int		len;

	len = 0;
	is_quote = 0;
	while (*word)
	{
		if (!is_quote && (*word == '\'' || *word == '\"'))
			is_quote = *word;
		else if (is_quote && (*word == is_quote))
			is_quote = 0;
		else
			len++;
		word++;
	}
	return (len);
}

void	get_delimiter(char **delimiter, int *quote, int dlen, char *word)
{
	int		is_quote;
	int		i;

	*delimiter = ft_malloc(sizeof(char) * (dlen + 1));
	*quote = (dlen != (int)ft_strlen(word));
	i = 0;
	is_quote = 0;
	while (*word)
	{
		if (!is_quote && (*word == '\'' || *word == '\"'))
			is_quote = *word;
		else if (is_quote && (*word == is_quote))
			is_quote = 0;
		else
			(*delimiter)[i++] = *word;
		word++;
	}
	(*delimiter)[i] = '\0';
}
