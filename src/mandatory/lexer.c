/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:33:23 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/06 17:05:45 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// token 리스트 반환하는 함수
// token 리스트 처음부터 끝까지 출력하는 함수
void	print_token_list();

int	is_blank(char c)
{
	return (c == ' ' || c == '\t');
}

int	count_tokens(char *str)
{
	int	cnt;

	cnt = 0;
	while (*(str + 1) && is_blank(*str) && !is_blank(*(str + 1)))
		cnt++;
	return (cnt);
}

#include <stdio.h>
int main()
{
	printf("%d\n", count_tokens("1 2 3   4  "));
	return 0;
}

