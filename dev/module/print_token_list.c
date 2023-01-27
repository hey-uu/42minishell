#include <stdio.h>
#include "s_token.h"

void	print_token_list(t_token *list)
{
	int	i;

	if (!list)
		return ;
	i = 0;
	while (list[i].type != TOKEN_NONE)
	{
		printf("%d: type %d %s\n", i, list[i].type, list[i].str);
		i++;
	}
}