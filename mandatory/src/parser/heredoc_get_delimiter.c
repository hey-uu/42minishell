/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_get_delimiter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:38:22 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 10:38:41 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_delimiter_len(char *word)
{
	int		quote;
	int		len;

	len = 0;
	quote = 0;
	while (*word)
	{
		if (!quote && (*word == '\'' || *word == '\"'))
			quote = *word;
		else if (quote && (*word == quote))
			quote = 0;
		else
			len++;
		word++;
	}
	return (len);
}

void	store_delimiter(char *delimiter, char *word)
{
	int		quote;
	int		i;

	i = 0;
	quote = 0;
	while (*word)
	{
		if (!quote && (*word == '\'' || *word == '\"'))
			quote = *word;
		else if (quote && (*word == quote))
			quote = 0;
		else
			delimiter[i++] = *word;
		word++;
	}
	delimiter[i] = '\0';
}
