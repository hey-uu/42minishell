/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 06:07:28 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/16 07:59:50 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expansion.h"
#include "libft.h"
#include <assert.h>
#include "env_manager.h"
#include <stdio.h>
#define WORD_CASE 4
char *word_case[] = {
	"aad\"$PATH\"$LOGNAME\"b\"",
	"a$PATH*",
	"A\"\"B",
	"\"\""
};

void	show_hash_table(t_hash_table *table);


int	main(int argc, char **argv, char **envp)
{
	t_env_tab	*table;
	t_expansion	*word;
	t_word		*node;
	int			i, j;

	argc++;
	argv++;
	initialize_env_table(&table, envp);
	show_hash_table(table);
	j = -1;
	while (++j < WORD_CASE)
	{
		printf("\n========================\n");
		printf("\n%dth test case: [%s]\n\n", j + 1, word_case[j]);
		word = expand_word(word_case[j], table);
		node = word->first;
		i = 0;
		while (node)
		{
			printf("%d : %s\n", ++i, node->data);
			node = node->next;
		}
		destroy_expansion(word);
		printf("\n========================\n");
	}
	hash_table_destroy(table);
}
