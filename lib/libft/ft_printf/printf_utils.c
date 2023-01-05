/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:58:33 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/17 10:01:22 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_option(t_option *opt)
{
	opt->flag = 0;
	opt->w = 0;
	opt->precision = 0;
	opt->padding = ' ';
	opt->out = 0;
	opt->len = 0;
}

int	find_flag(const char c, unsigned char *flag)
{
	const char	flags[5] = {'-', '+', ' ', '#', '0'};
	int			i;

	i = -1;
	while (++i < 5)
	{
		if (flags[i] == c)
		{
			*flag |= 1 << i;
			return (1);
		}
	}
	return (0);
}

int	find_identifier(const char c)
{
	const char	identifiers[9] = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X', '%'};
	int			i;

	i = -1;
	while (++i < 9)
		if (identifiers[i] == c)
			return (i);
	return (-1);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
