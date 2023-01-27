/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapped_syscall.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:50:36 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 18:50:55 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAPPED_SYSCALL_H
# define WRAPPED_SYSCALL_H

/*--------------- STANDARD HEADERS ---------------*/

# include <dirent.h>
# include <sys/types.h>

# define OPEN_MODE_NONE -1

int		w_unlink(const char *path);
DIR		*w_opendir(const char *filename);
int		w_closedir(DIR *dirp);
int		w_dup(int filedes);
int		w_dup2(int filedes, int filedes2);
int		w_fork(void);
int		w_wait(int *stat_loc);
int		w_open(const char *path, int oflag, int mode);
void	w_close(int fildes);
ssize_t	w_read(int fildes, void *buf, size_t nbyte);
ssize_t	w_write(int fildes, const void *buf, size_t nbyte);
void	*w_malloc(size_t size_of);


#endif