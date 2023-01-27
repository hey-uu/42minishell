
#include "tree.h"
#include "executor_internal.h"
#include "minishell.h"
#include "parser_internal.h"

int main(int argc, char **argv, char **envp)
{
	// char *str = "cat infile | cat >outfile && (cat outfile)";
	// char *str = "cat infile || cat outfile";

	// char *str = "cat a | cat";
	// char *str = "cat a | cat | cat";

	// char *str = "cat /dev/urandom | ls";
	// char *str = "cat /dev/urandom | ls | cat";
	// char *str = "echo mmmm | echo wwww | cat";
	// char *str = "cat /dev/urandom | ls | cat | cat";
	// char *str = "cat";
	// char *str = "cat | cat | ls";
	// char *str = "echo aaadf | cat";
	// char *str = "yes | head -3";

	// char *str = "(cat a) | cat b";
	// char *str = "(cat a) | echo pp";
		// 현 문제: (cat a)의 결과물이 파이프가 아닌 표준 출력에 쓰이고 있음.
	// char *str = "(cat a && cat b) | cat";
	// char *str = "(cat a && cat b)";
	// char *str = "(cat a && sleep 5 && cat b) | cat";

	t_node *tree = parser(lexer(str));
	// show_tree(tree, 0);
	executor(tree, envp);
}