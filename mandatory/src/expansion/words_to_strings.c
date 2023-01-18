/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_to_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:41:38 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 22:27:49 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "expansion_internal.h"
#include "env_manager.h"
#include "libadt.h"
#include "libft.h"

// * t_word가 NULL인 경우
// 1. ""인 경우 => 빈 문자열("") 반환
//  ---> command : quote removal 하기 직전이 ""인 경우 ""가 들어감
//  ---> command arguments : ""가 들어감
//  ---> heredoc : word가 ""인 경우 delimiter는 "", 즉 enter치면 종료됨
//  ---> redirection : ""로 들어감
// 2. 변수 확장 결과 아무 값도 없는 경우 => NULL 반환
//  ---> command : 아무 일도 안 인얼나고 다음 줄을 받음
//  ---> command arguments : 그냥 무시됨
//  ---> herdoc : 그냥 확장이 안 일어나기 때문에 아무 영향이 없음
//  ---> redirection : ambiguous redirect

static int	determine_string_length(t_word *cur)
{
	int		len;

// printf("> determine string length...\n");
	len = 0;
	while (cur)
	{
		len += cur->len;
// printf(">>> cur len : %d\n", cur->len);
		if (!(cur->next) || (cur->next->mask & EXPAND_SPLITTED) != 0)
			return (len);
		cur = cur->next;
	}
// printf(">>>>> total len : %d\n", len);
	return (len);
}

t_word	*fill_string_with_word_data(char *string, t_word *cur)
{
	int		i;

// printf("> fill string with word data...\n");
	i = 0;
	if (!cur)
		return (NULL);
	while (cur)
	{
		if (cur->len)
			ft_strlcpy(string + i, cur->data, cur->len + 1);
// printf(">>> filling... : [%s]\n", string);
		i += cur->len;
		if ((!cur->next) || (cur->next->mask & EXPAND_SPLITTED) != 0)
			return (cur);
		cur = cur->next;
	}
// printf(">>>>> total data : [%s]\n", cur->data);
	return (NULL);
}

char	*word_to_string(t_expansion *set)
{
	char	*string;
	int		len;
	t_word	*start;
	t_word	*end;

// printf("> one word to a string...\n");
	len = determine_string_length(set->first);
	if (!len && set->quote_exist == QUOTED_CHAR_NONE)
		return (NULL);
	string = ft_malloc(sizeof(char) * (len + 1));
	string[len] = 0;
	start = set->first;
	end = fill_string_with_word_data(string, set->first);
	if (end)
	{
		set->first = end->next;
		if (set->last == end)
			set->last = NULL;
		end->next = NULL;
	}
	destroy_words(start);
// printf(">>>>> result string... : [%s]\n", string);
	return (string);
}

char	**words_to_strings(t_expansion *set)
{
	char	**strings;
	int		count;
	int		i;

// printf("> words to strings...\n");
	count = set->count;
	strings = ft_malloc(sizeof(char *) * (count + 1));
	strings[count] = NULL;
	i = -1;
	while (++i < count)
	{
		strings[i] = word_to_string(set);
	}
// printf(">>>>> strings count: %d\n", count);
	return (strings);
}
