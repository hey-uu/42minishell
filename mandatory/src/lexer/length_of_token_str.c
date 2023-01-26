
#include "lexer.h"

int	length_of_operator(const int token_type)
{
	if (token_type == TOKEN_AND_IF \
		|| token_type == TOKEN_OR_IF \
		|| token_type == TOKEN_REDIR_IN_HERE \
		|| token_type == TOKEN_REDIR_OUT_APP)
		return (2);
	else
		return (1);
}

int	length_of_word(const char *input)
{
	int	len;
	int	quote;

	len = 0;
	quote = 0;
	while (input[len] && (quote || \
		(!is_blank(input[len]) && get_token_type(&input[len]) == TOKEN_WORD)))
	{
		if (!quote && (input[len] == '\'' || input[len] == '\"'))
			quote = input[len];
		else if (quote && input[len] == quote)
			quote = 0;
		len++;
	}
	if (quote)
		return (-1);
	return (len);
}
