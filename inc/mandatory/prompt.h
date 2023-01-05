/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:28:27 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/06 02:54:44 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

typedef enum e_prompt
{
	PS1_DOLLAR,
	PS2_REDIR
}	t_prompt;

void	print_prompt(t_prompt type);
void	print_welcome(void);


#endif