/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 22:24:08 by hyeyukim          #+#    #+#             */
/*   Updated: 2022/12/27 21:34:13 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>

typedef struct s_gnl_list
{
	int					fd;
	char				buff[BUFFER_SIZE];
	ssize_t				rbytes;
	size_t				offset;
	size_t				new_len;
	size_t				len;
	struct s_gnl_list	*next;
}	t_gnl_list;

char		*get_next_line(int fd);
int			read_buffer_size(t_gnl_list **head, t_gnl_list *cur, char *res);
char		*append_line(\
			t_gnl_list **head, t_gnl_list *cur, char **res, int option);
t_gnl_list	*create_node(int fd);
int			find_node(t_gnl_list **head, t_gnl_list **cur, int fd);
int			process_error(t_gnl_list **head, t_gnl_list *cur, char *str);

#endif