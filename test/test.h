/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:05:32 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/08 00:12:18 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

#include "minishell.h"
#include <stdio.h>
#include <assert.h>

# define TOKEN_ERROR -1

int	count_tokens(char *input);

#endif