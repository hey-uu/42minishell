/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:50:28 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/01 23:19:42 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_exit(const char *str, int error_status)
{
	if (str && error_status != 0)
		write(2, str, ft_strlen(str));
	else if (str)
		write(1, str, ft_strlen(str));
	exit(error_status);
}
