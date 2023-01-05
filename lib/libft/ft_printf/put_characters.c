/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_characters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:59:40 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/17 10:01:22 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

int	put_percent(t_option *opt, va_list ap)
{
	if (!ap)
		return (-1);
	opt->len = opt->w + (opt->w == 0);
	opt->out = malloc(opt->len);
	if (!opt->out)
		return (-1);
	ft_memset(opt->out, opt->padding, opt->len);
	if ((opt->flag & 01) == 01)
		opt->out[0] = '%';
	else
		opt->out[opt->len - 1] = '%';
	return (write(1, opt->out, opt->len));
}

int	put_chr(t_option *opt, va_list ap)
{
	const char	c = (char) va_arg(ap, int);

	opt->len = opt->w + (opt->w == 0);
	opt->out = malloc(opt->len);
	if (!opt->out)
		return (-1);
	ft_memset(opt->out, opt->padding, opt->len);
	if ((opt->flag & 01) == 01)
		opt->out[0] = c;
	else
		opt->out[opt->len - 1] = c;
	return (write(1, opt->out, opt->len));
}

int	put_str(t_option *opt, va_list ap)
{
	const char	*str = va_arg(ap, char *);
	int			str_len;

	if (!str)
		str = "(NULL)";
	str_len = ft_strlen(str);
	if ((opt->flag & 32) == 32 && str_len > opt->precision)
		str_len = opt->precision;
	opt->len = ft_max(str_len, opt->w);
	opt->out = malloc(opt->len);
	if (!opt->out)
		return (-1);
	ft_memset(opt->out, opt->padding, opt->len);
	if ((opt->flag & 1) == 1)
		ft_memcpy(opt->out, str, str_len);
	else
		ft_memcpy(opt->out + opt->len - str_len, str, str_len);
	return (write(1, opt->out, opt->len));
}
