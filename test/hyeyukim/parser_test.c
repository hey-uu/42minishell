/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 07:09:38 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/09 09:19:38 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

// make -C ../../lib/libft adt
// gcc -Wall -Wextra -Werror parser_test.c ../../src/mandatory/parser.c ../../src/mandatory/lexer.c -I../../inc/mandatory -I../../lib/libft/includes/. -lft -L../../lib/libft -fsanitize=address -g3
void	print_indent(int depth)
{
	int	i;
	i = -1;
	while (++i < depth * 3)
		printf(" ");
}

void	print_arguments(t_simple_command *simple, int depth)
{
	int	i;

	print_indent(depth);
	printf("arguments:\n");
	print_indent(depth);
	printf("[\n");
	i = -1;
	while (++i < simple->argv->used_size)
	{
		print_indent(depth + 1);
		printf("%s\n", simple->argv->strarr[(simple->argv->front + i) % simple->argv->size]);
	}
	print_indent(depth);
	printf("]\n");
}

void	print_redirection_in(t_simple_command *simple, int depth)
{
	int			type;
	int			i;

	print_indent(depth);
	printf("redirection in : \n");
	print_indent(depth);
	printf("[\n");
	i = -1;
	while (++i < simple->redir_in->used_size)
	{
		print_indent(depth + 1);
		type = simple->redir_in->iarr[(simple->redir_in->front + i) % simple->redir_in->size];
		if (type == TOKEN_REDIR_IN)
			printf("type : <\n");
		else
			printf("type : <<\n");
		print_indent(depth + 1);
		printf("file name : %s\n", simple->redir_in->strarr[(simple->redir_in->front + i) % simple->redir_in->size]);	
	}
	print_indent(depth);
	printf("]\n");
}

void	print_redirection_out(t_simple_command *simple, int depth)
{
	int	type;
	int	i;

	print_indent(depth);
	printf("redirection out : \n");
	print_indent(depth);
	printf("[\n");
	i = -1;
	while (++i < simple->redir_out->used_size)
	{
		print_indent(depth + 1);
		type = simple->redir_out->iarr[(simple->redir_out->front + i) % simple->redir_out->size];
		if (type == TOKEN_REDIR_OUT)
			printf("type : >\n");
		else
			printf("type : >>\n");
		print_indent(depth + 1);
		printf("file name : %s\n", simple->redir_out->strarr[(simple->redir_out->front + i) % simple->redir_out->size]);	
	}
	print_indent(depth);
	printf("]\n");
}

void	show_simple_command(t_simple_command *simple, int depth)
{
	print_indent(depth);
	printf("command name : %s\n", simple->cmd_name);
	print_arguments(simple, depth);
	print_redirection_in(simple, depth);
	print_redirection_out(simple, depth);
}

void	show_subshell(t_subshell *subshell, int depth)
{
	print_indent(depth);
	printf("%d\n", subshell->check);
}

void	print_type(int type)
{
	static char	*str_type[] = {"none", "simple_command", "subshell", "pipeline", "&&", "||"};

	printf("type : %s\n", str_type[type]);
}

void	show_tree(t_tree *tree, int depth)
{
	if (!tree)
		return;
	print_indent(depth);
	if (depth)
		printf("{\n");
	print_indent(depth + 1);
	print_type(tree->type);
	if (tree->type == NODE_SIMPLE_COMMAND)
		show_simple_command(tree->content.simple, depth + 1);
	if (tree->type == NODE_SUBSHELL)
		show_subshell(tree->content.subshell, depth + 1);
	if (tree->first_child)
		show_tree(tree->first_child, depth + 1);
	print_indent(depth);
	printf("}\n");
	if (tree->next_sibling)
		show_tree(tree->next_sibling, depth);
}

int	main(void)
{
	t_token	*arr = lexer("> suffix a -l < hi << hello && b | c && d");
	t_tree	*tree = parser(arr);

	show_tree(tree, 0);
	destroy_parse_tree(tree);
	while (1)
	{
		system("leaks a.out");
		sleep(1);
	}
}