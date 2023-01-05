/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:47:08 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/11/15 22:08:22 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>

t_gnl_list	*create_node(int fd)
{
	t_gnl_list	*new;

	new = malloc(sizeof(t_gnl_list));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->rbytes = BUFFER_SIZE;
	new->offset = BUFFER_SIZE;
	new->new_len = 0;
	new->len = 1;
	new->next = NULL;
	return (new);
}

int	find_node(t_gnl_list **head, t_gnl_list **cur, int fd)
{
	t_gnl_list	*tem;

	if (!*head)
	{
		*head = create_node(fd);
		if (!*head)
			return (0);
	}
	tem = *head;
	while (tem && (tem)->fd != fd)
	{
		if (!(tem)->next)
		{
			(tem)->next = create_node(fd);
			if (!(tem)->next)
				return (0);
		}
		tem = (tem)->next;
	}
	*cur = tem;
	return (1);
}

int	process_error(t_gnl_list **head, t_gnl_list *cur, char *str)
{
	t_gnl_list	*tem;

	if (str)
		free(str);
	tem = *head;
	if (tem == cur)
	{
		*head = tem->next;
		free(cur);
		return (0);
	}
	while (tem->next)
	{
		if (tem->next == cur)
		{
			tem->next = cur->next;
			free(cur);
			break ;
		}
		tem = tem->next;
	}
	return (0);
}

char	*append_line(t_gnl_list **head, t_gnl_list *cur, char **res, int option)
{
	char	*new;

	new = malloc(cur->new_len + cur->len + 1);
	if (!new)
	{
		process_error(head, cur, *res);
		return (NULL);
	}
	if (*res)
	{
		ft_strlcpy(new, *res, cur->new_len + 1);
		free(*res);
	}
	ft_strlcpy(new + cur->new_len, \
				&cur->buff[1 + cur->offset - cur->len], cur->len + 1);
	cur->new_len += cur->len;
	cur->len = 1;
	if (option)
	{
		cur->new_len = 0;
		cur->offset++;
		cur->len = 1;
	}
	*res = new;
	return (new);
}

int	read_buffer_size(t_gnl_list **head, t_gnl_list *cur, char *res)
{
	cur->rbytes = read(cur->fd, cur->buff, BUFFER_SIZE);
	if (cur->rbytes < 0)
		return (process_error(head, cur, res));
	cur->offset = 0;
	cur->len = 1;
	return (1);
}
