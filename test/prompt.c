#include <stdio.h>
#include "shell.h"

void	print_welcome(void)
{
	char	*str;

	str = "The default interactive shell is now zsh. \
To update your account to use zsh, please run `chsh -s /bin/zsh`. \
For more details, please visit https://support.apple.com/kb/HT208050.";
	fprintf(stderr, str);
}

void	print_prompt1(void)
{
	fprintf(stderr, "$ ");
}

void	print_prompt2(void)
{
	fprintf(stderr, "> ");
}
