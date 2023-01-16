/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 06:07:28 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 23:36:21 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "libft.h"
#include <assert.h>
#include "env_manager.h"
#include <stdio.h>
#include <stdlib.h>

#define WORD_CASE 4
char *word_case[] = {
	"aad\"$PATH\"$LOGNAME\"b\"",
	"a$PATH*",
	"A\"\"B",
	"\"\""
};

void	show_hash_table(t_hash_table *table);

void	destroy_strings(char **strings)
{
	int	i;

	i = -1;
	while (strings[++i])
	{
		free(strings[i]);
	}
	free(strings);
}

int	main(int argc, char **argv, char **envp)
{
	t_env_tab	*table;
	t_expansion	*set;
	char		**strings;
	int			i;
	int			j;

	argc++;
	argv++;
	table = initialize_env_table(envp);
	show_hash_table(table);
	j = -1;
	while (++j < WORD_CASE)
	{
		printf("\n========================\n");
		printf("\n%dth test case: [%s]\n\n", j + 1, word_case[j]);
		set = expand_word(word_case[j]);
		strings = words_to_strings(set, 0);
		i = -1;
		printf("\n");
		while (strings[++i])
		{
			printf("%d : %s\n", i + 1, strings[i]);
		}
		destroy_expansion(set);
		destroy_strings(strings);
		strings = NULL;
		printf("\n========================\n");
	}
	hash_table_flush(table);
}
