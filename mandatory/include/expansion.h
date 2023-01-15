/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:43:40 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/15 22:54:23 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANSION_H
# define EXPANSION_H


enum e_is_quoted
{
	EXP_UNQUOTED,
	EXP_SQUOTED,
	EXP_DQUOTED,
	EXP_SPLITTED
};

typedef struct s_word
{
	char			*data;
	int				len;
	int				quote;
	struct s_word	*next;
}	t_word;

typedef struct s_expansion
{
	t_env_tab	*envtab;
	char		*origin;
	int			origin_len;
	t_word		*head;
	t_word		*last;
	int			count;
}	t_expansion;

#endif