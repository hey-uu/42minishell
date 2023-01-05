/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:58:15 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/17 10:01:22 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

static int	print_identifier(const char *format, int *i, va_list ap)
{
	const t_fct	put[9] = {put_chr, put_str, put_ptr, put_nbr, put_nbr, \
					put_unbr, put_xunbr_lower, put_xunbr_upper, put_percent};
	t_option	opt;
	int			res;

	init_option(&opt);
	while (find_flag(format[++(*i)], &opt.flag))
		;
	while (ft_isdigit(format[*i]))
		opt.w = opt.w * 10 + format[(*i)++] - '0';
	if (format[*i] == '.')
	{
		opt.flag |= 1 << 5;
		while (ft_isdigit(format[++(*i)]))
			opt.precision = opt.precision * 10 + format[*i] - '0';
	}
	if ((opt.flag & 49) == 16)
		opt.padding = '0';
	res = put[find_identifier(format[*i])](&opt, ap);
	free(opt.out);
	return (res);
}

static int	print_with_no_identifier(const char *format, int *i)
{
	int	tem;

	tem = 1;
	while (format[*i + tem] && format[*i + tem] != '%')
		tem++;
	tem = write(1, format + *i, tem);
	*i += (tem - 1);
	return (tem);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			i;
	int			tem;
	int			res;

	va_start(ap, format);
	res = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
			tem = print_identifier(format, &i, ap);
		else
			tem = print_with_no_identifier(format, &i);
		if (tem < 0)
			return (-1);
		res += tem;
	}
	va_end(ap);
	return (res);
}
