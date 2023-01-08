/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:33:26 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/09 08:36:08 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tree *create_tree_node(void)
{
	t_tree *new;

	new = ft_malloc(sizeof(t_tree));
	new->type = NODE_NONE;
	new->content.simple = NULL;
	new->content.subshell = NULL;
	new->first_child = NULL;
	new->next_sibling = NULL;
	return (new);
}

t_simple_command	*create_simple_command(void)
{
	t_simple_command	*new;

	new = ft_malloc(sizeof(t_simple_command));
	new->cmd_name = NULL;
	new->argv = create_queue(QUEUE_INITIAL_SIZE, QUEUE_STR_ONLY);
	new->redir_in = create_queue(QUEUE_INITIAL_SIZE, QUEUE_INTSTR);
	new->redir_out = create_queue(QUEUE_INITIAL_SIZE, QUEUE_INTSTR);
	return (new);
}

void	destroy_simple_command(t_simple_command *simple)
{
	if (simple->cmd_name)
		free(simple->cmd_name);
	destroy_queue(simple->argv);
	destroy_queue(simple->redir_in);
	destroy_queue(simple->redir_out);
}

int	parse_subshell(t_tree *node, t_token *token, int offset)
{
	node->type = NODE_SUBSHELL;
	node->content.subshell->check = 1;
	printf("%d\n", token[offset].type);
	return (1);
}

int	is_redirection(int type)
{
	if (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_IN_HERE || \
		type == TOKEN_REDIR_OUT || type == TOKEN_REDIR_OUT_APP)
		return (1);
	return (0);
}

void	push_redirection(t_simple_command *simple, t_token *token, int offset)
{
	const int	type = token[offset].type;
	const char	*str = ft_strdup(token[offset + 1].str);

	if (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_IN_HERE)
		queue_push_intstr(simple->redir_in, (int)type, (char *)str);
	else
		queue_push_intstr(simple->redir_out, (int)type, (char *)str);
}

void	push_arguments(t_simple_command *simple, t_token *token, int offset)
{
	const char	*str = ft_strdup(token[offset].str);

	queue_push_str(simple->argv, (char *)str);
}


int	parse_prefix(t_simple_command *simple, t_token *token, int offset)
{
	int	cnt;

	cnt = 0;
	while (is_redirection(token[offset + cnt].type))
	{
		if (token[offset + cnt + 1].type == TOKEN_WORD)
			push_redirection(simple, token, offset + cnt);
		else
			return (-1);
		cnt += 2;
	}
	return (cnt);
}

int	parse_command_name(t_simple_command *simple, t_token *token, int offset)
{
	if (token[offset].type == TOKEN_WORD)
	{
		simple->cmd_name = ft_strdup(token[offset].str);
		push_arguments(simple, token, offset);
		return (1);
	}
	return (0);
}

int	parse_suffix(t_simple_command *simple, t_token *token, int offset)
{
	int	cnt;

	cnt = 0;
	while (1)
	{
		if (token[offset + cnt].type == TOKEN_WORD)
		{
			push_arguments(simple, token, offset + cnt);
			cnt++;
		}
		else if (is_redirection(token[offset + cnt].type))
		{
			if (token[offset + cnt + 1].type == TOKEN_WORD)
				push_redirection(simple, token, offset + cnt);
			else
				return (-1);
			cnt += 2;
		}
		else
			break ;
	}
	return (cnt);
}

int	parse_simple_command(t_tree *node, t_token *token, int offset)
{
	int	res[3];

	node->type = NODE_SIMPLE_COMMAND;
	node->content.simple = create_simple_command();
	res[0] = parse_prefix(node->content.simple, token, offset);
	if (res[0] == -1)
	{
		destroy_simple_command(node->content.simple);
		return (0);
	}
	res[1] = parse_command_name(node->content.simple, token, offset + res[0]);
	res[2] = parse_suffix(node->content.simple, token, offset + res[0] + res[1]);
	if (res[2] == -1 || (res[0] + res[1] + res[2]) == 0)
	{
		destroy_simple_command(node->content.simple);
		return (0);
	}
	return (res[0] + res[1] + res[2]);
}

int	parse_command(t_tree *node, t_token *tokens, int offset)
{
	int	res;

	if (tokens[offset].type == TOKEN_LPAREN)
		res = parse_subshell(node, tokens, offset);
	else
		res = parse_simple_command(node, tokens, offset);
	return (res);
}

int	parse_pipeline(t_tree *node, t_token *tokens, int offset)
{
	t_tree	*cur_node;
	int		cnt;
	int		res;

	node->type = NODE_PIPELINE;
	node->first_child = create_tree_node();
	res = parse_command(node->first_child, tokens, offset);
	if (!res)
		return (0);
	cnt = res;
	cur_node = node->first_child;
	while (tokens[offset + cnt].type == TOKEN_PIPE)
	{
		cnt++;
		cur_node->next_sibling = create_tree_node();
		res = parse_command(cur_node->next_sibling, tokens, offset + cnt);
		if (!res)
			return (0);
		cnt += res;
	}
	return (cnt);
}

int	parse_list(t_tree **root, t_token *tokens, int offset)
{
	t_tree	*node; // 이중 포인터를 쓰면 코드가 어지러워져서 변수 사용함
	int		cnt; // 함수에서 총 처리한 토큰 수
	int		res; // parsing 함수 반환값

	node = *root;
	node->first_child = create_tree_node(); // 왼쪽 자식 노드 생성
	res = parse_pipeline(node->first_child, tokens, offset); // pipeline 파싱
	// syntax 에러 처리
	if (!res)
		return (0);
	cnt = res;
	// pipeline 뒤에 && 연산자나 || 연산자가 오는 경우
	if (tokens[offset + cnt].type == TOKEN_AND_IF)
		node->type = NODE_AND_IF;
	else if (tokens[offset + cnt].type == TOKEN_OR_IF)
		node->type = NODE_OR_IF;
	// 단일한 pipeline으로 이루어져 있는 경우
	else
	{
		*root = node->first_child;
		free(node);
		return (cnt);
	}
	cnt++;
	node->first_child->next_sibling = create_tree_node(); // 오른쪽 자식 노드 생성
	res = parse_list(&(node->first_child->next_sibling), tokens, offset + cnt); // 재귀로 list 파싱
	if (!res)
		return (0);
	cnt += res;
	return (cnt);
}

void	destroy_tokens(t_token *tokens)
{
	int	i;

	i = -1;
	while (tokens[++i].type != TOKEN_NONE)
		free(tokens[i].str);
	free(tokens);
}

void	destroy_subshell(t_subshell *subshell)
{
	subshell->check= 0;
}

void	destroy_parse_tree(t_tree *node)
{
	if (node->first_child)
		destroy_parse_tree(node->first_child);
	if (node->next_sibling)
		destroy_parse_tree(node->next_sibling);
	if (node->type == NODE_SIMPLE_COMMAND)
		destroy_simple_command(node->content.simple);
	if (node->type == NODE_SUBSHELL)
		destroy_subshell(node->content.subshell);
	free(node);
}

t_tree	*parser(t_token *tokens)
{
	t_tree	*parse_tree;
	int		token_num;

	parse_tree = create_tree_node();
	token_num = parse_list(&parse_tree, tokens, 0);
	printf("token_nums : %d\n", token_num);
	destroy_tokens(tokens);
	if (g_goldsh.syntax_error == NONE)
		return (parse_tree);
	else
	{
		// print_parse_error_message(g_goldsh.syntax_error);
		destroy_parse_tree(parse_tree);
		return (NULL);
	}
}
