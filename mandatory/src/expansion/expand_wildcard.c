/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:07:27 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/24 17:35:45 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "expansion_internal.h"
#include "libft.h"
#include "libadt.h"
#include <sys/types.h>
#include <dirent.h>

char	*get_next_file_name()
{
	static DIR				*dir_ptr;
	static struct dirent	*file;
	char					*file_name;

	if (!dir_ptr)
	{
		dir_ptr = opendir(".");
	}
	file = readdir(dir_ptr);
	while (file)
	{
		file_name = file->d_name;
		if (ft_strncmp(file_name, ".", 2) && ft_strncmp(file_name, "..", 3))
			return (file_name);
		file = readdir(dir_ptr);
	}
	closedir(dir_ptr);
	dir_ptr = NULL;
	return (NULL);
}

int	get_pattern_char(t_word *word, int i)
{
	int				tem;
	int				len;
	unsigned char	c;
	int				j;

	tem = -1;
	j = -1;
	while (i > tem)
	{
		len = word->elem_arr[++j].len;
		tem += len;
// printf("i: %d, j: %d, len: %d, tem: %d\n", i, j, len, tem);
	}
// printf("%d\n", len);
// printf("data: %s, %d\n", word->elem_arr[j].data, word->elem_arr[j].len);
	if (word->elem_arr[j].type & WELEM_WILDCARD)
		return (IS_WILDCARD);
// printf("this is not wildcard!\n");
	if (i == tem)
		c = (unsigned char) word->elem_arr[j].data[len - 1];
	else
		c = (unsigned char) word->elem_arr[j].data[i - tem + len - 1];
	return ((int)c);
}

int	get_pattern_len(t_word *word)
{
	int	pattern_len;
	int	i;

	i = 0;
	pattern_len = 0;
	while (i < word->elem_cnt)
	{
		pattern_len += word->elem_arr[i].len;
		i++;
	}
	return (pattern_len);
}

void	init_lookup_table(t_bool ***table, int pattern_len, int string_len)
{
	int	i;

	*table = ft_calloc(string_len + 1, sizeof(t_bool *));
	i = 0;
	while (i < string_len + 1)
	{
		(*table)[i] = ft_calloc(pattern_len + 1, sizeof(t_bool));
		i++;
	}
}

void	destroy_lookup_table(t_bool ***table,int string_len)
{
	int	i;

	i = 0;
	while (i < string_len + 1)
	{
		free((*table)[i]);
		i++;
	}
	free(*table);
	*table = NULL;
}

void	fill_lookup_table(t_bool **lookup, t_word *word, char *str, int len[2])
{
	int	i;
	int	j;
	int	c;

	lookup[0][0] = 1;
	j = 1;
	while (j <= len[0])
	{
// printf("pattern char: %d: %d\n", j - 1, get_pattern_char(word, j - 1));
		if (get_pattern_char(word, j - 1) == IS_WILDCARD)
			lookup[0][j] = lookup[0][j - 1];
		j++;
	}
	i = 1;
	while (i <= len[1])
	{
		j = 1;
		while (j <= len[0])
		{
			c = get_pattern_char(word, j - 1);
// printf("pattern char: %d %d: %d\n", i, j, c);
			if (c == IS_WILDCARD)
			{
				lookup[i][j] = (lookup[i][j - 1] || lookup[i - 1][j]);
// printf("this is wildcard: %d\n", lookup[i][j]);
			}
			else if (c == (unsigned char)str[i - 1])
			{
				lookup[i][j] = lookup[i - 1][j - 1];
// printf("%d == %c, %d\n", c, (unsigned char) str[i - 1], lookup[i][j]);
			}
			else
				lookup[i][j] = 0;
// printf("lookup table: %d\n", lookup[i][j]);
			j++;
		}
		i++;
	}
}

int	is_matching(t_word	*word, char *string)
{
	const int	pattern_len = get_pattern_len(word);
	const int	string_len = ft_strlen(string);
	t_bool		**lookup;
	t_bool		res;

// printf("lens: %d, %d\n", pattern_len, string_len);
	init_lookup_table(&lookup, pattern_len, string_len);
	fill_lookup_table(lookup, word, string, (int [2]){pattern_len, string_len});
	res = lookup[string_len][pattern_len];
	destroy_lookup_table(&lookup, string_len);
	return (res);
}

void	push_wildcard_expansion_to_strings(t_word *word, t_darr *strings)
{
	char	*file_name;
	int		count;

	count = 0;
	while (1)
	{
		file_name = get_next_file_name();
// printf("file name : %s\n", file_name);
		if (!file_name)
			break ;
		if (is_matching(word, file_name))
		{
// printf("this matched!: %s\n", file_name);
			darr_push_str(strings, ft_strdup(file_name));
			count++;
		}
	}
	if (!count)
		push_word_to_strings(word, strings);
}