/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:00:11 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/14 18:48:02 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://www.partow.net/programming/hashfunctions/index.html
// file:///C:/Users/user/Downloads/14750.pdf
// https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)HashTables.html?highlight=%28CategoryAlgorithmNotes%29
// https://cseweb.ucsd.edu/~kube/cls/100/Lectures/lec16/lec16-12.html

#include "hash_table.h"
#include "libft.h"
#include <stdio.h>
int	hash_polynomial_31(char *string)
{
	const int	len = ft_strlen(string);
	int			i;
	int			hash;

	hash = 0;
	i = -1;
	while (++i < len)
	{
		hash = 31 * hash + string[i];
	}
	return (hash);
}

int	hash_bucket(char *string, int bucket_cnt)
{
	int	hash_value;
	
	hash_value = hash_polynomial_31(string);
	hash_value %= bucket_cnt;
	if (hash_value < 0)
		hash_value *= -1;
	return (hash_value);
}