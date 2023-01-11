/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:07:43 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/11 09:41:56 by hyeyukim         ###   ########.fr       */
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
	printf("|--* ");
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
		printf("%s\n", argv->strarr[(argv->front + i) % argv->size]);
	}
	print_indent2(depth);
	printf("]\n");
}

static void	print_redirection_in(t_queue *redir_in, int depth)
{
	int			type;
	int			i;

	print_indent2(depth);
	printf("redirection in : [\n");
	i = -1;
	while (++i < redir_in->used_size)
	{
		print_indent3(depth + 1);
		type = redir_in->iarr[(redir_in->front + i) % redir_in->size];
		if (type == TOKEN_REDIR_IN)
			printf("type : <\n");
		else
			printf("type : <<\n");
		print_indent3(depth + 1);
		printf("file name : %s\n", \
				redir_in->strarr[(redir_in->front + i) % redir_in->size]);
	}
	print_indent2(depth);
	printf("]\n");
}

static void	print_redirection_out(t_queue *redir_out, int depth)
{
	int	type;
	int	i;

	print_indent2(depth);
	printf("redirection out : [\n");
	i = -1;
	while (++i < redir_out->used_size)
	{
		print_indent3(depth + 1);
		type = redir_out->iarr[(redir_out->front + i) % redir_out->size];
		if (type == TOKEN_REDIR_OUT)
			printf("type : >\n");
		else
			printf("type : >>\n");
		print_indent3(depth + 1);
		printf("file name : %s\n", \
				redir_out->strarr[(redir_out->front + i) % redir_out->size]);
	}
	print_indent2(depth);
	printf("]\n");
}

static void	show_simple_command(t_execute_unit *unit, int depth)
{
	print_indent2(depth);
	printf("command name : %s\n", unit->simple_cmd->name);
	print_arguments(unit->simple_cmd->argv, depth);
	print_redirection_in(unit->io_list->redir_in, depth);
	print_redirection_out(unit->io_list->redir_out, depth);
}

static void	show_subshell(t_node *tree, int depth)
{
	print_redirection_in(tree->exe_unit.io_list->redir_in, depth);
	print_redirection_out(tree->exe_unit.io_list->redir_out, depth);
}

static void	print_type(int type)
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
	print_type(tree->type);
	if (tree->type == NODE_SIMPLE_CMD)
		show_simple_command(&tree->exe_unit, depth + 1);
	if (tree->type == NODE_SUBSHELL)
		show_subshell(tree, depth + 1);
	if (tree->first_child)
		show_tree(tree->first_child, depth + 1);
	print_indent2(depth);
	printf("}\n");
	if (tree->next_sibling)
		show_tree(tree->next_sibling, depth);
}