/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_internal.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:37:54 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/14 01:55:38 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_INTERNAL_H
# define HASH_TABLE_INTERNAL_H

/*------------- STRUCT DECLARATIONS --------------*/

typedef struct s_hash_content
{
	char					*key;
	char					*content;
	struct s_hash_content	*next;
}	t_hash_content;


typedef struct	s_hash_table
{
	t_hash_content	**arr;
	int				bucket_cnt;
	int				entry_cnt;
}	t_hash_table;

typedef t_hash_table	t_hash_tab;

#endif