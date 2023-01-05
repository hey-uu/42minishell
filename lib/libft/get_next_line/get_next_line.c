/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:26:36 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/15 22:08:22 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_gnl_list	*head = NULL;
	t_gnl_list			*cur;
	char				*res;

	if (BUFFER_SIZE <= 0 || fd < 0 || !find_node(&head, &cur, fd))
		return (NULL);
	res = NULL;
	while (1)
	{
		if (cur->offset == (size_t) cur->rbytes)
			if (!read_buffer_size(&head, cur, res))
				return (NULL);
		if (cur->rbytes == 0)
			if (!process_error(&head, cur, NULL))
				return (res);
		if (cur->buff[cur->offset] == '\n')
			return (append_line(&head, cur, &res, 1));
		if (cur->offset == (size_t) cur->rbytes - 1)
			if (!append_line(&head, cur, &res, 0))
				return (NULL);
		cur->offset++;
		cur->len++;
	}
}
