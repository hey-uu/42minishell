/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonhkim <yeonhkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:52:47 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/28 16:16:32 by yeonhkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_BONUS_H
# define BUILTIN_BONUS_H

/*-------------- FUNCTION PROTOTYPES -------------*/

void	builtin_echo(char *argv[]);
void	builtin_cd(char *argv[]);
void	builtin_pwd(char *argv[]);
void	builtin_export(char *argv[]);
void	builtin_env(char *argv[]);
void	builtin_exit(char *argv[]);
void	builtin_unset(char *argv[]);

#endif