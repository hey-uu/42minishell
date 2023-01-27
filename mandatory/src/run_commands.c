#include "minishell.h"
#include "handle_error.h"

static void	execute(t_node *parse_tree, int *errcode)
{
	if (*errcode == FAILURE)
		return ;
	*errcode = executor(parse_tree);
}

static void	make_parse_tree(t_token *tokens, t_node **parse_tree, int *errcode)
{
	if (*errcode == FAILURE)
		return ;
	*errcode = parser(tokens, parse_tree);
}

static void	tokenizing(char *input, t_token **token_list, int *errcode)
{
	*errcode = lexer(input, token_list);
	return ;
}

static void	free_allocated_memory(t_token *token_list, t_node *parse_tree)
{
	destroy_token_list(token_list);
	destroy_tree(parse_tree);
	return ;
}

void	run_commands(char *input)
{
	t_token	*token_list;
	t_node	*parse_tree;
	int		errcode;

	errcode = 0;
	tokenizing(input, &token_list, &errcode);
	make_parse_tree(token_list, &parse_tree, &errcode);
	execute(parse_tree, &errcode);
	free_allocated_memory(token_list, parse_tree);
}
