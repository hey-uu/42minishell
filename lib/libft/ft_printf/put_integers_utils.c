/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_integers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:59:49 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/03 20:07:26 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_nbrlen(long n, int base_len, t_option *opt)
{
	int	len;

	if (n == 0 && opt->precision == 0 && (opt->flag & 32) == 32)
		return (0);
	len = (n == 0);
	while (n != 0)
	{
		n /= base_len;
		len++;
	}
	if (opt->precision > len)
		return (opt->precision);
	return (len);
}

int	ft_unbrlen(unsigned long n, int base_len, t_option *opt)
{
	int	len;

	if (n == 0 && opt->precision == 0 && (opt->flag & 32) == 32)
		return (0);
	len = (n == 0);
	while (n > 0)
	{
		n /= base_len;
		len++;
	}
	if (opt->precision > len)
		return (opt->precision);
	return (len);
}

void	decide_nbr_sign(t_option *opt, long nbr, int nbr_len)
{
	int	idx;

	if ((opt->flag & 1) == 1 || (opt->flag & 48) == 16)
		idx = 0;
	else
		idx = opt->len - nbr_len - 1;
	if (nbr < 0)
		opt->out[idx] = '-';
	else if ((opt->flag & 2) == 2)
		opt->out[idx] = '+';
	else if ((opt->flag & 4) == 4)
		opt->out[idx] = ' ';
}

void	decide_xunbr_hash(t_option *opt, int xunbr_len, int upper)
{
	int	idx;

	if ((opt->flag & 1) == 1 || (opt->flag & 48) == 16)
		idx = 0;
	else
		idx = opt->len - xunbr_len - 2;
	if ((opt->flag & 8) == 8)
	{
		opt->out[idx] = '0';
		opt->out[idx + 1] = 'x' * (upper == 0) + 'X' * (upper == 1);
	}
}

void	unbrtostr(char *str_nbr, unsigned long nbr, int nbr_len, char *base)
{
	const int	base_len = ft_strlen(base);

	while (nbr != 0 && (--nbr_len) >= 0)
	{	
		str_nbr[nbr_len] = base[nbr % base_len];
		nbr /= base_len;
	}
	while (--nbr_len >= 0)
		str_nbr[nbr_len] = '0';
}
