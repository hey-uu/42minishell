/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:33:26 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/09 17:14:39 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// 파싱하면서 heredoc 처리 (확정은 아니고 고려중)
// - redir_in queue에 delimiter를 저장하지 않고
// - 생성한 임시 파일의 이름을 저장할 것

// malloc 실패한 경우 처리에 대해 고민해보자

// create : malloc을 통해 동적 메모리 할당하는 함수
t_node	*create_node(void)
{
	t_node	*new;

	new = ft_malloc(sizeof(t_node));
	new->type = NODE_NONE;
	new->exe_unit.simple_cmd = NULL;
	new->exe_unit.io_list = NULL;
	new->first_child = NULL;
	new->next_sibling = NULL;
	return (new);
}

t_simple_cmd	*create_simple_command(void)
{
	t_simple_cmd	*new;

	new = ft_malloc(sizeof(t_simple_cmd));
	new->name = NULL;
	new->argv = create_queue(QUEUE_INITIAL_SIZE, QUEUE_STR_ONLY);
	return (new);
}

t_redir_list	*create_redirect_list(void)
{
	t_redir_list	*new;

	new = ft_malloc(sizeof(t_redir_list));
	new->redir_in = create_queue(QUEUE_INITIAL_SIZE, QUEUE_INTSTR);
	new->redir_out = create_queue(QUEUE_INITIAL_SIZE, QUEUE_INTSTR);
	return (new);
}

// destroy : free를 통해서 동적으로 할당된 메모리를 해제하는 함수
void	destroy_simple_command(t_simple_cmd *simple)
{
	destroy_queue(simple->argv);
	free(simple);
}

void	destroy_redirect_list(t_redir_list *io_list)
{
	destroy_queue(io_list->redir_in);
	destroy_queue(io_list->redir_out);
	free(io_list);
}

void	destroy_parse_tree(t_node *parent)
{
	if (!parent)
		return ;
	destroy_parse_tree(parent->first_child);
	destroy_parse_tree(parent->next_sibling);
	if (parent->type == NODE_SIMPLE_CMD)
	{
		destroy_simple_command(parent->exe_unit.simple_cmd);
		destroy_redirect_list(parent->exe_unit.io_list);
	}
	if (parent->type == NODE_SUBSHELL)
		destroy_redirect_list(parent->exe_unit.io_list);
	free(parent);
}

// redirection(<, >, <<, >>)이면 1, 아니면 0을 반환하는 함수
int	is_redirection(int type)
{
	if (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_IN_HERE || \
		type == TOKEN_REDIR_OUT || type == TOKEN_REDIR_OUT_APP)
		return (1);
	return (0);
}

// redirection queue에 token type(int) 및 file_name/here_end(char *)를 추가하는 함수
void	push_redirection(t_redir_list *io_list, t_token *token, int offset)
{
	const int	type = token[offset].type;
	const char	*str = token[offset + 1].str;

	if (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_IN_HERE)
		queue_push_intstr(io_list->redir_in, (int)type, (char *)str);
	else
		queue_push_intstr(io_list->redir_out, (int)type, (char *)str);
}

// arguments queue에 실행하고자 하는 명령어 및 명령어 인자(char *)를 추가하는 함수
void	push_arguments(t_simple_cmd *simple_cmd, t_token *token, int offset)
{
	const char	*str = token[offset].str;

	queue_push_str(simple_cmd->argv, (char *)str);
}

// <subshell>	: TOKEN_LPAREN <list> TOKEN_RPAREN
//				| <subshell> <redirect_list>
int	parse_subshell(t_node *node, t_token *tokens, int offset)
{
	int	cnt;
	int	res;

	cnt = 0;
	node->type = NODE_SUBSHELL;
	if (tokens[offset + cnt].type != TOKEN_LPAREN)
		return (0);
	cnt++;
	node->first_child = create_node();
	res = parse_list(&node->first_child, tokens, offset + cnt);
	if (!res)
		return (0);
	cnt += res;
	if (tokens[offset + cnt].type != TOKEN_RPAREN)
		return (0);
	cnt++;
	node->exe_unit.io_list = create_redirect_list();
	while (is_redirection(tokens[offset + cnt].type))
	{
		if (tokens[offset + cnt + 1].type == TOKEN_WORD)
			push_redirection(node->exe_unit.io_list, tokens, offset);
		else
			return (0);
		cnt += 2;
	}
	return (cnt);
}

// <cmd_prefix>	: <io_redirect>
//				| <io_redirect> <cmd_prefix>
int	parse_prefix(t_redir_list *io_list, t_token *token, int offset)
{
	int	cnt;

	cnt = 0;
	while (is_redirection(token[offset + cnt].type))
	{
		if (token[offset + cnt + 1].type == TOKEN_WORD)
			push_redirection(io_list, token, offset + cnt);
		else
			return (-1);
		cnt += 2;
	}
	return (cnt);
}

// <cmd_name>	: WORD
int	parse_command_name(t_simple_cmd *simple_cmd, t_token *token, int offset)
{
	if (token[offset].type == TOKEN_WORD)
	{
		simple_cmd->name = token[offset].str;
		push_arguments(simple_cmd, token, offset);
		return (1);
	}
	return (0);
}

// <cmd_suffix>	: WORD
//				| <io_redirect>
//				| WORD <cmd_suffix>
//				| <io_redirect> <cmd_suffix>
int	parse_suffix(t_execute_unit *unit, t_token *token, int offset)
{
	int	cnt;

	cnt = 0;
	while (1)
	{
		if (token[offset + cnt].type == TOKEN_WORD)
		{
			push_arguments(unit->simple_cmd, token, offset + cnt);
			cnt++;
		}
		else if (is_redirection(token[offset + cnt].type))
		{
			if (token[offset + cnt + 1].type == TOKEN_WORD)
				push_redirection(unit->io_list, token, offset + cnt);
			else
				return (-1);
			cnt += 2;
		}
		else
			break ;
	}
	return (cnt);
}

// <simple_command>	: <cmd_prefix>
//					| <cmd_prefix> <cmd_name>
//					| <cmd_prefix> <cmd_name> <cmd_suffix>
//					| <cmd_name>
//					| <cmd_suffix>
int	parse_simple_command(t_node *node, t_token *token, int offset)
{
	int	res[3];

	node->type = NODE_SIMPLE_CMD;
	node->exe_unit.simple_cmd = create_simple_command();
	node->exe_unit.io_list = create_redirect_list();
	res[0] = parse_prefix(node->exe_unit.io_list, token, offset);
	if (res[0] == -1)
		return (0);
	res[1] = parse_command_name(\
			node->exe_unit.simple_cmd, token, offset + res[0]);
	res[2] = parse_suffix(\
			&node->exe_unit, token, offset + res[0] + res[1]);
	if (res[2] == -1 || (res[0] + res[1] + res[2]) == 0)
		return (0);
	return (res[0] + res[1] + res[2]);
}

// <command>		: <simple_command>
//					| <subshell>
int	parse_command(t_node *node, t_token *tokens, int offset)
{
	int	res;

	if (tokens[offset].type == TOKEN_LPAREN)
		res = parse_subshell(node, tokens, offset);
	else
		res = parse_simple_command(node, tokens, offset);
	return (res);
}

// <pipeline>		: <command>
//					| <pipeline> TOKEN_PIPE <pipeline>
int	parse_pipeline(t_node *parent, t_token *tokens, int offset)
{
	t_node	*cur_node;
	int		cnt;
	int		res;

	parent->type = NODE_PIPELINE;
	parent->first_child = create_node();
	res = parse_command(parent->first_child, tokens, offset);
	if (!res)
		return (0);
	cnt = res;
	cur_node = parent->first_child;
	while (tokens[offset + cnt].type == TOKEN_PIPE)
	{
		cnt++;
		cur_node->next_sibling = create_node();
		res = parse_command(cur_node->next_sibling, tokens, offset + cnt);
		if (!res)
			return (0);
		cnt += res;
	}
	return (cnt);
}

// list				: <pipeline>
//					| <list> TOKEN_AND_IF <list>
//					| <list> TOKEN_OR_IF <list>
int	parse_list(t_node **root, t_token *tokens, int offset)
{
	t_node	*node; // 이중 포인터를 쓰면 코드가 어지러워져서 변수 사용함
	int		cnt; // 함수에서 총 처리한 토큰 수
	int		res; // parsing 함수 반환값

	node = *root;
	node->first_child = create_node(); // 왼쪽 자식 노드 생성
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
	node->first_child->next_sibling = create_node(); // 오른쪽 자식 노드 생성
	res = parse_list(&(node->first_child->next_sibling), tokens, offset + cnt); // 재귀로 list 파싱
	if (!res)
		return (0);
	cnt += res;
	return (cnt);
}

t_node	*parser(t_token *tokens)
{
	t_node	*parse_tree;
	int		token_num;

	parse_tree = create_node();
	token_num = parse_list(&parse_tree, tokens, 0);
	printf("token_nums : %d\n", token_num);
	free(tokens);
	if (g_goldsh.syntax_error == NONE)
		return (parse_tree);
	else
	{
		// print_parse_error_message(g_goldsh.syntax_error);
		destroy_parse_tree(parse_tree);
		return (NULL);
	}
}
