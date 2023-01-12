/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:07:43 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/11 14:55:47 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

static void	print_indent1(int depth)
{
	int	i;

	if (depth < 1)
		return ;
	i = -1;
	while (++i < depth - 2)
		printf("|  ");
	printf("|--*  ");
}

static void	print_indent2(int depth)
{
	int	i;

	if (!depth)
		return ;
	i = -1;
	while (++i < depth)
		printf("|  ");
}

static void	print_indent3(int depth)
{
	int	i;

	if (!depth)
		return ;
	i = -1;
	while (++i < depth - 1)
		printf("|  ");
	printf("   ");
}

static void	print_arguments(t_queue *argv, int depth)
{
	int	i;

	print_indent2(depth);
	printf("arguments: [\n");
	i = -1;
	while (++i < argv->used_size)
	{
		print_indent3(depth + 1);
		printf("+ %s\n", argv->strarr[(argv->front + i) % argv->size]);
	}
	print_indent2(depth);
	printf("]\n");
}

static void	print_redirect_type(int type)
{
	if (type == TOKEN_REDIR_IN)
		printf("+ type : <\n");
	else if (type == TOKEN_REDIR_IN_HERE)
		printf("+ type : <<\n");
	else if (type == TOKEN_REDIR_OUT)
		printf("+ type : >\n");
	else if (type == TOKEN_REDIR_OUT_APP)
		printf("+ type : >>\n");
}

static void	print_redirect_list(t_queue *redir_list, int depth)
{
	int	type;
	int	i;

	print_indent2(depth);
	printf("redirection : [\n");
	i = -1;
	while (++i < redir_list->used_size)
	{
		print_indent3(depth + 1);
		type = redir_list->iarr[(redir_list->front + i) % redir_list->size];
		print_redirect_type(type);
		print_indent3(depth + 1);
		printf("  file name : %s\n", \
				redir_list->strarr[(redir_list->front + i) % redir_list->size]);
	}
	print_indent2(depth);
	printf("]\n");
}

static void	show_simple_command(t_execute_unit *unit, int depth)
{
	print_indent2(depth);
	printf("command name : %s\n", unit->cmd_name);
	print_arguments(unit->cmd_argv, depth);
	print_redirect_list(unit->redir_list, depth);
}

static void	show_subshell(t_node *tree, int depth)
{
	print_redirect_list(tree->exe_unit->redir_list, depth);
}

static void	print_node_type(int type)
{
	static char	*str_type[] = {"none", "simple_command", "subshell", \
							"pipeline", "&&", "||"};

	printf("type : %s\n", str_type[type]);
}

void	show_tree(t_node *tree, int depth)
{
	if (!tree)
		return ;
	print_indent2(depth);
	if (!depth)
		printf("\n{\n*  ");
	else
	{
		printf("children :\n");
		print_indent2(depth);
		printf("{\n");
		print_indent1(depth + 1);
	}
	print_node_type(tree->type);
	if (tree->type == NODE_SIMPLE_CMD)
		show_simple_command(tree->exe_unit, depth + 1);
	if (tree->type == NODE_SUBSHELL)
		show_subshell(tree, depth + 1);
	if (tree->first_child)
		show_tree(tree->first_child, depth + 1);
	print_indent2(depth);
	printf("}\n");
	if (tree->next_sibling)
		show_tree(tree->next_sibling, depth);
}
