/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:50:28 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/10 20:48:26 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft_internal.h"

void	ft_exit(const char *str, int error_status)
{
	if (str && error_status != 0)
		write(2, str, ft_strlen(str));
	else if (str)
		write(1, str, ft_strlen(str));
	exit(error_status);
}
