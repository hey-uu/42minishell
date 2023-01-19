/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:53:40 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/18 23:53:42 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	builtin_echo(char **argv)
{
	argv++;
	printf("this is built-in echo\n");
	return (0);
}

int	builtin_cd(char **argv)
{
	argv++;
	printf("this is built-in cd\n");
	return (0);
}

int	builtin_pwd(char **argv)
{
	argv++;
	printf("this is built-in pwd\n");
	return (0);
}

int	builtin_export(char **argv)
{
	argv++;
	printf("this is built-in export\n");
	return (0);
}

int	builtin_env(char **argv)
{
	argv++;
	printf("this is built-in env\n");
	return (0);
}

int	builtin_exit(char **argv)
{
	argv++;
	printf("this is built-in exit\n");
	return (0);
}
