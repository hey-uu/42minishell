/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:28:27 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/06 08:47:57 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_H
# define PROMPT_H

# define PS1_DOLLAR "goldsh $ "
# define PS2_REDIR "goldsh > "

typedef enum e_prompt
{
	E_PS1_DOLLAR,
	E_PS2_REDIR
}	t_prompt;

void	print_prompt(t_prompt type);
void	print_welcome(void);


#endif