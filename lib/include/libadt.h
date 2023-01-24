/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libadt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:58:02 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/25 00:41:53 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBADT_H
# define LIBADT_H

/*-------------- USER DEFINED HEADERS ------------*/

# include "../libadt/dynamic_array/t_dynamic_array.h"
# include "../libadt/hash_table/t_hash_table.h"
# include "../libadt/list/t_list.h"
# include "../libadt/queue/t_queue.h"

/*------------ DEFINE MACRO CONSTANTS ------------*/

# define QUEUE_INITIAL_SIZE 10

/*-------------- FUNCTION PROTOTYPES -------------*/

/*** dynamic array ***/
// darr_create.c
void			init_dynamic_array(t_darr *darr, int initial_size, int type);
t_darr			*create_dynamic_array(int initial_size, int type);
// darr_destroy.c
void			darr_flush(t_darr *darr);
void			destroy_darr(t_darr **darr);
// darr_get_arr.c
int				*darr_get_int_arr(t_darr *darr);
char			**darr_get_str_arr(t_darr *darr);
t_intstr		*darr_get_intstr_arr(t_darr *darr);
// darr_pop.c
int				darr_pop_int(t_darr *deq);
char			*darr_pop_str(t_darr *deq);
t_intstr		darr_pop_intstr(t_darr *deq);
// darr_push.c
void			darr_push_int(t_darr *darr, int new_num);
void			darr_push_str(t_darr *darr, char *new_str);
void			darr_push_intstr(t_darr *darr, int new_num, char *new_str);
void			darr_push_strs(t_darr *darr, char **strs);
// darr_show.c
void			darr_show(t_darr *queue);

/*** hash_table ***/

// hash_function.c
int				hash_bucket(char *string, int bucket_cnt);
// hash_table_create.c
void			hash_table_init(t_hash_table *table);
t_hash_table	*hash_table_create(void);
// hash_table_destroy.c
void			hash_table_delete(t_hash_table *hash_table, char *key);
void			hash_table_flush(t_hash_table *hash_table);
void			hash_table_destroy(t_hash_table *hash_table);
// hash_table_insert.c
void			hash_table_insert(\
				t_hash_table *table, char *key, void *content);
// hash_table_search.c
t_hash_content	*hash_table_search(t_hash_table *table, char *key, int bucket);
// hash_table_update.c
void			hash_table_update(\
				t_hash_table *hash_table, char *key, void *content);

/*** linked list ***/

// list_add.c
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
// list_create.c
t_list			*ft_lstnew(void *content);
// list_destroy.c
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
// list_iterate.c
void			ft_lstiter(t_list *lst, void (*f)(void *));
// list_map.c
t_list			*ft_lstmap(\
				t_list *lst, void *(*f)(void *), void (*del)(void *));
// list_utils.c
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
int				ft_lstsize(t_list *lst);

/*** queue ***/

// queue_create.c
t_queue			*create_queue(int initial_size, int type);
// queue_destroy.c
void			queue_flush(t_queue *queue);
void			destroy_queue(t_queue **queue);
// queue_get.c
int				queue_get_int(t_queue *queue, int i);
char			*queue_get_str(t_queue *queue, int i);
t_intstr		queue_get_intstr(t_queue *queue, int i);
int				queue_get_idx(t_queue *queue, int i);
int				*queue_get_int_arr(t_queue *queue);
char			**queue_get_str_arr(t_queue *queue);
t_intstr		*queue_get_intstr_arr(t_queue *queue);

// queue_pop.c
int				queue_pop_int(t_queue *deq);
char			*queue_pop_str(t_queue *deq);
t_intstr		queue_pop_intstr(t_queue *deq);
// queue_push.c
void			queue_push_int(t_queue *queue, int new_data);
void			queue_push_str(t_queue *queue, char *new_data);
void			queue_push_intstr(t_queue *queue, int idata, char *sdata);
void			queue_push_strs(t_queue *queue, char **strs);
// queue_show.c
void			queue_show(t_queue *queue);

#endif