/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:52:47 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/27 11:53:12 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

/*-------------- FUNCTION PROTOTYPES -------------*/

// builtin
void	builtin_echo(char *argv[]);
void	builtin_cd(char *argv[]);
void	builtin_pwd(char *argv[]);
void	builtin_export(char *argv[]);
void	builtin_env(char *argv[]);
void	builtin_exit(char *argv[]);
void	builtin_unset(char *argv[]);

#endif