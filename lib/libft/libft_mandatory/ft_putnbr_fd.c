/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:03:13 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/10/27 14:03:14 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	arr[11];
	long	tem;
	int		i;

	tem = (long) n;
	if (tem == 0)
		write(fd, "0", 1);
	else if (tem < 0)
	{
		tem *= -1;
		write(fd, "-", 1);
	}
	i = 0;
	while (tem > 0)
	{
		arr[i++] = tem % 10 + '0';
		tem /= 10;
	}
	while (--i >= 0)
		write(fd, &arr[i], 1);
}
