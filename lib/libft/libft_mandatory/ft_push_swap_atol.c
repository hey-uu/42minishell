/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_atol.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:02:58 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/03 20:42:20 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isdigit(int c);
static long	ft_push_swap_strtol(int sign, const char *str);

long	ft_push_swap_atol(const char *str)
{
	int		sign;
	long	num;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str || (*str && !ft_isdigit(*str)))
		ft_exit("Error\n", 1);
	while (*str && *str == '0')
		str++;
	if (*str)
		num = ft_push_swap_strtol(sign, str);
	else
		return (0);
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (num);
}

long	ft_push_swap_strtol(int sign, const char *str)
{
	long	num;
	int		i;
	long	check;

	i = -1;
	num = 0;
	while (ft_isdigit(str[++i]) == 1)
	{
		if (i == 18)
		{
			check = num - 922337203685477580;
			if (sign == 1 && (check > 0 || (check == 0 && str[i] >= '7') \
				|| ft_isdigit(str[i + 1])))
				return (FT_LONG_MAX);
			else if (sign == -1 && (check > 0 || (check == 0 && str[i] >= '8') \
				|| ft_isdigit(str[i + 1])))
				return (-FT_LONG_MAX - 1);
		}
		num = num * 10 + str[i] - '0';
	}
	return (num * sign);
}
