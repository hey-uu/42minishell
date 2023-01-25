/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:42:55 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 17:47:22 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAP_H
# define WRAP_H

/*--------------- STANDARD HEADERS ---------------*/

# include <dirent.h>

int	w_access(const char *path, int mode);
DIR	*w_opendir(const char *filename);
int	w_closedir(DIR *dirp);
int	w_dup(int filedes);
int	w_dup2(int filedes, int filedes2);
int	w_fork(void);
int	w_wait(int *stat_loc);


#endif