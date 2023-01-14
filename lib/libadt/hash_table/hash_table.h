/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 00:37:54 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/14 23:05:36 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_H
# define HASH_TABLE_H

/*------------ DEFINE MACRO CONSTANTS ------------*/

# define INITIAL_BUCKET_CNT 1
# define LOAD_FACTOR 2
# define GROW_MULTIPLIER 4
# define SHRINK_DIVISOR 2

// debug
# include <stdio.h>

/*------------- STRUCT DECLARATIONS --------------*/

typedef struct s_hash_content
{
	char					*key;
	void					*content;
	struct s_hash_content	*prev;
	struct s_hash_content	*next;
}	t_hash_content;


typedef struct	s_hash_table
{
	t_hash_content	**bucket_arr;
	int				bucket_cnt;
	int				entry_cnt;
}	t_hash_table;

typedef int	(*t_hash_fct)(char *);


/*-------------- FUNCTION PROTOTYPES -------------*/

// hash function
int				hash_polynomial_31(char *string);
int				hash_bucket(char *string, int bucket_cnt);

// hash table
t_hash_table	*hash_table_create(void);
void			hash_table_insert_entry(\
				t_hash_content **bucket_arr, t_hash_content *entry, int bucket);
void			hash_table_insert(t_hash_table *table, char *key, void *content);
t_hash_content	*hash_table_search(t_hash_table *table, char *key, int bucket);
void			hash_table_update(t_hash_table *hash_table, char *key, void *content);
void			hash_table_delete(t_hash_table *hash_table, char *key);
void			hash_table_destroy(t_hash_table *hash_table);
void			hash_table_grow(t_hash_table *hash_table);
void			hash_table_shrink(t_hash_table *hash_table);

#endif