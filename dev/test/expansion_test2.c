/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_test2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 22:28:35 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 23:34:37 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft.h"
#include "lexer.h"
#include "parser.h"
#include "expansion.h"
#include "env_manager.h"

#define WORD_CASE 25
#define VARIABLE_NUM 6

extern char	**environ;

char	*variables[][2] = {
	{"var1", "a b c"},
	{"var2", "$PATH"},
	{"var3", "AB C D"},
	{"a", "1 2 3"},
	{"b", "1 2 3 4"},
	{"c", ""}
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
	"1$a\"$a\"$b\"$b\"$\'$\'", // 19
	"$c", // 20
	"", // 21
	"\"\"abc", // 22
	"\"\"\'\'$c", // 23
	"$c\'\'", // 24
	"\'$c\'\"\"" // 25
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

void	leak_check(void)
{
	printf("\n\n* check leaks!\n");
	system("leaks expand_test");
}

void	print_command(char *cmd_name)
{
	printf(">>> command : [%s]\n", cmd_name);
}

void	print_command_arguments(t_queue *cmd_argv)
{
	int		i;
	char	*argv;

	i = 0;
	printf(">>> command arguments : \n");
	while (i < cmd_argv->used_size)
	{
		argv = queue_get_str(cmd_argv, i);
		printf(">>>>> [%s]\n", argv);
		i++;
	}
}

void	print_redirections(t_queue *redir_list)
{
	int		i;
	int		type;
	char	*argv;

	i = 0;
	printf(">>> redirection list : \n");
	while (i < redir_list->used_size)
	{
		type = queue_get_int(redir_list, i);
		argv = queue_get_str(redir_list, i);
		printf(">>>>> ");
		if (type == TOKEN_REDIR_IN)
			printf("type: [<] ");
		else if (type == TOKEN_REDIR_IN_HERE)
			printf("type: [<<] ");
		else if (type == TOKEN_REDIR_OUT)
			printf("type: [>] ");
		else if (type == TOKEN_REDIR_OUT_APP)
			printf("type: [>>] ");
		else
			printf("error!!!!!\n");
		printf("argv: [%s]\n", argv);
		i++;
	}
}

void	print_expansion_status(t_execute_unit *unit)
{
	print_command(unit->cmd_name);
	print_command_arguments(unit->cmd_argv);
	print_redirections(unit->redir_list);
}

void	test_expansion(t_tree_node *node)
{
	int		res;

	if (!node)
		return ;
	if (node->first_child)
	{
		printf("this is first child!\n");
		test_expansion(node->first_child);
	}
	if (node->next_sibling)
	{
		printf("this is next sibling!\n");
		test_expansion(node->next_sibling);
	}
	if (node->type == NODE_SIMPLE_CMD || node->type == NODE_SUBSHELL)
	{
		res = do_expansion(node->exe_unit);
		if (res == EXPAND_SUCCESS)
			printf("=====> success <=====\n");
		else
			printf("=====> failed <=====\n");
		print_expansion_status(node->exe_unit);
	}
}


int	main(void)
{
	t_env_tab	*table;
	t_token		*token_list;
	t_tree_node	*parse_tree;
	char		*line;

#ifdef FSANITIZE_FLAG
	atexit(leak_check);
#endif
	table = init_env_table(environ);
	set_variables();
	while (1)
	{
		printf("\n=======================================\n");
		line = readline("test > ");
		if (!line)
			break ;
		token_list = lexer(line);
		parse_tree = parser(token_list);
		test_expansion(parse_tree);
		free(line);
		destroy_tree(parse_tree);
		printf("\n=======================================\n");
	}
	hash_table_flush(table);
}
