/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_internal.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:37:54 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/17 11:36:38 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_INTERNAL_H
# define HASH_TABLE_INTERNAL_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "t_hash_table.h"

//debug
# include <stdio.h>

/*-------------- FUNCTION PROTOTYPES -------------*/

// hash function
int				hash_bucket(char *string, int bucket_cnt);

// search method
t_hash_content	*hash_table_search(t_hash_table *table, char *key, int bucket);

// insert method
void			__hash_table_insert_entry__(\
				t_hash_content **bucket_arr, t_hash_content *entry, int bucket);
void			hash_table_insert(\
				t_hash_table *table, char *key, void *content);

// resize hash table
void			__hash_table_grow__(t_hash_table *hash_table);
void			__hash_table_shrink__(t_hash_table *hash_table);

#endif