/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_integers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:59:54 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/17 10:01:22 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

int	put_nbr(t_option *opt, va_list ap)
{
	long	nbr;
	int		nbr_len;
	int		sign;

	nbr = (long) va_arg(ap, int);
	nbr_len = ft_nbrlen(nbr, 10, opt);
	sign = (nbr < 0 || (opt->flag & 6) != 0);
	opt->len = ft_max(opt->w, nbr_len + sign);
	opt->out = malloc(opt->len);
	if (!opt->out)
		return (-1);
	ft_memset(opt->out, opt->padding, opt->len);
	decide_nbr_sign(opt, nbr, nbr_len);
	if (nbr < 0)
		nbr *= -1;
	if ((opt->flag & 1) == 1)
		unbrtostr(opt->out + sign, nbr, nbr_len, DEC);
	else
		unbrtostr(opt->out + opt->len - nbr_len, nbr, nbr_len, DEC);
	return (write(1, opt->out, opt->len));
}

int	put_unbr(t_option *opt, va_list ap)
{
	const unsigned long	unbr = va_arg(ap, unsigned int);
	const int			unbr_len = ft_unbrlen(unbr, 10, opt);

	opt->len = ft_max(opt->w, unbr_len);
	opt->out = malloc(opt->len);
	if (!opt->out)
		return (-1);
	ft_memset(opt->out, opt->padding, opt->len);
	if ((opt->flag & 1) == 1)
		unbrtostr(opt->out, unbr, unbr_len, DEC);
	else
		unbrtostr(opt->out + opt->len - unbr_len, unbr, unbr_len, DEC);
	return (write(1, opt->out, opt->len));
}

int	put_ptr(t_option *opt, va_list ap)
{
	const unsigned long	ptr = (unsigned long) va_arg(ap, void *);
	const int			ptr_len = ft_unbrlen(ptr, 16, opt);

	opt->len = ft_max(opt->w, ptr_len + 2);
	opt->out = malloc(opt->len);
	if (!opt->out)
		return (-1);
	ft_memset(opt->out, opt->padding, opt->len);
	if ((opt->flag & 1) == 1)
	{
		ft_memcpy(opt->out, "0x", 2);
		unbrtostr(opt->out + 2, ptr, ptr_len, HDL);
	}
	else
	{
		ft_memcpy(opt->out + opt->len - ptr_len - 2, "0x", 2);
		unbrtostr(opt->out + opt->len - ptr_len, ptr, ptr_len, HDL);
	}
	return (write(1, opt->out, opt->len));
}

int	put_xunbr_lower(t_option *opt, va_list ap)
{
	const unsigned int	xunbr = va_arg(ap, unsigned int);
	const int			xunbr_len = ft_unbrlen(xunbr, 16, opt);
	const int			hash = ((opt->flag & 8) == 8 && xunbr > 0) * 2;

	opt->len = ft_max(opt->w, xunbr_len + hash);
	opt->out = malloc(opt->len);
	if (!opt->out)
		return (-1);
	ft_memset(opt->out, opt->padding, opt->len);
	if (xunbr > 0)
		decide_xunbr_hash(opt, xunbr_len, 0);
	if ((opt->flag & 1) == 1)
		unbrtostr(opt->out + hash, xunbr, xunbr_len, HDL);
	else
		unbrtostr(opt->out + opt->len - xunbr_len, xunbr, xunbr_len, HDL);
	return (write(1, opt->out, opt->len));
}

int	put_xunbr_upper(t_option *opt, va_list ap)
{
	const unsigned int	xunbr = va_arg(ap, unsigned int);
	const int			xunbr_len = ft_unbrlen(xunbr, 16, opt);
	const int			hash = ((opt->flag & 8) == 8 && xunbr > 0) * 2;

	opt->len = ft_max(opt->w, xunbr_len + hash);
	opt->out = malloc(opt->len);
	if (!opt->out)
		return (-1);
	ft_memset(opt->out, opt->padding, opt->len);
	if (xunbr > 0)
		decide_xunbr_hash(opt, xunbr_len, 1);
	if ((opt->flag & 1) == 1)
		unbrtostr(opt->out + hash, xunbr, xunbr_len, HDU);
	else
		unbrtostr(opt->out + opt->len - xunbr_len, xunbr, xunbr_len, HDU);
	return (write(1, opt->out, opt->len));
}
