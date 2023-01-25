/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 10:03:28 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 16:25:38 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_internal.h"

static size_t	get_wordcount(char const *s, char c)
{
	size_t	word_count;
	size_t	i;

	word_count = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] != c) && (s[i + 1] == '\0' || s[i + 1] == c))
			word_count++;
		i++;
	}
	return (word_count);
}

static size_t	ft_getlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	ft_free_all(char **res, size_t pos)
{
	size_t	i;

	i = 0;
	while (i < pos)
		free(res[i++]);
	free(res);
}

static t_bool	is_fill_split_ok(char **res, char const *s, char c)
{
	size_t	len;
	size_t	i;
	size_t	res_idx;

	res_idx = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = ft_getlen(&s[i], c);
			res[res_idx] = malloc(len + 1);
			if (!res[res_idx])
			{
				ft_free_all(res, res_idx);
				return (FALSE);
			}
			ft_strlcpy(res[res_idx], &s[i], len + 1);
			i += (len - 1);
			res_idx++;
		}
		i++;
	}
	res[res_idx] = NULL;
	return (TRUE);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**res;

	if (!s)
		return (NULL);
	word_count = get_wordcount(s, c);
	res = malloc(sizeof(char *) * (word_count + 1));
	if (res && is_fill_split_ok(res, s, c))
		return (res);
	return (NULL);
}
