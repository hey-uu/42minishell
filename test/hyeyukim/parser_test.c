/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 07:09:38 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/09 17:18:56 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

// make -C ../../lib/libft adt
// gcc -Wall -Wextra -Werror parser_test.c ../../src/mandatory/parser.c ../../src/mandatory/lexer.c -I../../inc/mandatory -I../../lib/libft/includes/. -lft -L../../lib/libft

void	print_indent(int depth)
{
	int	i;

	i = -1;
	while (++i < depth * 3)
		printf(" ");
}

void	print_arguments(t_queue *argv, int depth)
{
	int	i;

	print_indent(depth);
	printf("arguments: [\n");
	i = -1;
	while (++i < argv->used_size)
	{
		print_indent(depth + 1);
		printf("%s\n", argv->strarr[(argv->front + i) % argv->size]);
	}
	print_indent(depth);
	printf("]\n");
}

void	print_redirection_in(t_queue *redir_in, int depth)
{
	int			type;
	int			i;

	print_indent(depth);
	printf("redirection in : [\n");
	i = -1;
	while (++i < redir_in->used_size)
	{
		print_indent(depth + 1);
		type = redir_in->iarr[(redir_in->front + i) % redir_in->size];
		if (type == TOKEN_REDIR_IN)
			printf("type : <\n");
		else
			printf("type : <<\n");
		print_indent(depth + 1);
		printf("file name : %s\n", \
				redir_in->strarr[(redir_in->front + i) % redir_in->size]);
	}
	print_indent(depth);
	printf("]\n");
}

void	print_redirection_out(t_queue *redir_out, int depth)
{
	int	type;
	int	i;

	print_indent(depth);
	printf("redirection out : [\n");
	i = -1;
	while (++i < redir_out->used_size)
	{
		print_indent(depth + 1);
		type = redir_out->iarr[(redir_out->front + i) % redir_out->size];
		if (type == TOKEN_REDIR_OUT)
			printf("type : >\n");
		else
			printf("type : >>\n");
		print_indent(depth + 1);
		printf("file name : %s\n", \
				redir_out->strarr[(redir_out->front + i) % redir_out->size]);
	}
	print_indent(depth);
	printf("]\n");
}

void	show_simple_command(t_execute_unit *unit, int depth)
{
	print_indent(depth);
	printf("command name : %s\n", unit->simple_cmd->name);
	print_arguments(unit->simple_cmd->argv, depth);
	print_redirection_in(unit->io_list->redir_in, depth);
	print_redirection_out(unit->io_list->redir_out, depth);
}

void	show_subshell(t_node *tree, int depth)
{
	print_indent(depth);
	print_redirection_in(tree->exe_unit.io_list->redir_in, depth);
	print_redirection_out(tree->exe_unit.io_list->redir_out, depth);
}

void	print_type(int type)
{
	static char	*str_type[] = {"none", "simple_command", "subshell", \
							"pipeline", "&&", "||"};

	printf("type : %s\n", str_type[type]);
}

void	show_tree(t_node *tree, int depth)
{
	if (!tree)
		return ;
	print_indent(depth);
	if (depth)
		printf("{\n");
	print_indent(depth + 1);
	print_type(tree->type);
	if (tree->type == NODE_SIMPLE_CMD)
		show_simple_command(&tree->exe_unit, depth + 1);
	if (tree->type == NODE_SUBSHELL)
		show_subshell(tree, depth + 1);
	if (tree->first_child)
		show_tree(tree->first_child, depth + 1);
	print_indent(depth);
	printf("}\n");
	if (tree->next_sibling)
		show_tree(tree->next_sibling, depth);
}

#define TESTSTR "> suffix a -l < hi << hello && (b) | c && d"

int	main(void)
{
	t_token	*arr;
	t_node	*tree;

	arr = lexer(TESTSTR);
	tree = parser(arr);
	show_tree(tree, 0);
	destroy_parse_tree(tree);
	tree = 0;
	while (1)
	{
		system("leaks a.out");
		sleep(5);
	}
}
