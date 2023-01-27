/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapped_syscall.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yona <yona@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:50:36 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 02:59:26 by yona             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAPPED_SYSCALL_H
# define WRAPPED_SYSCALL_H

/*--------------- STANDARD HEADERS ---------------*/

# include <dirent.h>
# include <sys/types.h>

/*------------ DEFINE MACRO CONSTANTS ------------*/

# define OPEN_MODE_NONE -1

/*-------------- FUNCTION PROTOTYPES -------------*/

/* memory allocation */
void	*w_malloc(size_t size_of);

/* process */
int		w_fork(void);
int		w_wait(int *stat_loc);

/* directory operations */
DIR		*w_opendir(const char *filename);
int		w_closedir(DIR *dirp);

/* file open & close & unlink */
int		w_open(const char *path, int oflag, int mode);
void	w_close(int fildes);
int		w_unlink(const char *path);

/* input & output */
ssize_t	w_read(int fildes, void *buf, size_t nbyte);
ssize_t	w_write(int fildes, const void *buf, size_t nbyte);

/* duplicate file descriptor */
int		w_dup(int filedes);
int		w_dup2(int filedes, int filedes2);

#endif