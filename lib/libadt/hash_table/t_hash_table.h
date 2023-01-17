/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_hash_table.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:48:38 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/17 10:49:24 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_HASH_TABLE_H
# define T_HASH_TABLE_H

/*------------ DEFINE MACRO CONSTANTS ------------*/

# define INITIAL_BUCKET_CNT 1
# define LOAD_FACTOR 2
# define GROW_MULTIPLIER 4
# define SHRINK_DIVISOR 2

/*------------- STRUCT DECLARATIONS --------------*/

typedef struct s_hash_content
{
	char					*key;
	void					*content;
	struct s_hash_content	*prev;
	struct s_hash_content	*next;
}	t_hash_content;

typedef struct s_hash_table
{
	t_hash_content	**bucket_arr;
	int				bucket_cnt;
	int				entry_cnt;
}	t_hash_table;

typedef int	(*t_hash_fct)(char *);

#endif