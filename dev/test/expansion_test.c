/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 06:07:28 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 15:39:07 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "expansion.h"
#include "libft.h"
#include <assert.h>
#include "env_manager.h"
#include <stdio.h>
#include <stdlib.h>

#define WORD_CASE 19
#define VARIABLE_NUM 5

char	*variables[][2] = {
	{"var1", "a b c"},
	{"var2", "$PATH"},
	{"var3", "AB C D"},
	{"a", "1 2 3"},
	{"b", "1 2 3 4"}
};

char	*word_case[] = {
	"aad\"$PATH\"$LOGNAME\"b\"", // 1
	"a$PATH*", // 2
	"A\"\"B", // 3
	"\"\"", // 4
	"$?", // 5
	"$\"?\"", //6
	"$\'PATH'?", // 7
	"$\"PATH\"?", // 8
	"$\"\'\'\"", // 9
	"ADF$B*", // 10
	"$var1", // 11
	"\'$var2\'", // 12
	"start$var3?end", // 13
	"asdd$?'$PATH'", // 14
	"$", // 15
	"abc$", // 16
	"\"$\"", // 17
	"\'$\'", // 18
	"1$a\"$a\"$b\"$b\"$\'$\'" // 19
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

void	set_variables(void)
{
	int	i;

	i = -1;
	while (++i < VARIABLE_NUM)
		env_set(ft_strdup(variables[i][0]), ft_strdup(variables[i][1]));
}

void	check(void)
{
	printf("\n\n* check leaks!\n");
	system("leaks expand_test");
}

int	main(int argc, char **argv, char **envp)
{
	t_env_tab	*table;
	t_expansion	*set;
	char		**strings;
	int			i;
	int			j;

	atexit(check);
	argc++;
	argv++;
	table = init_env_table(envp);
	set_variables();
	show_hash_table(table);
	j = -1;
	while (++j < WORD_CASE)
	{
		printf("\n=======================================\n");
		printf("\n<<%dth test case: [%s]>>\n\n", j + 1, word_case[j]);
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
		printf("\n=======================================n");
	}
	hash_table_flush(table);
}
