/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_malloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:32:37 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/26 22:54:07 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "error_handle.h"

void	*w_malloc(size_t size_of)
{
	void	*new;

	new = malloc(size_of);
	if (!new)
	{
		handle_execute_error();
		exit(1);
	}
	return (new);
}
