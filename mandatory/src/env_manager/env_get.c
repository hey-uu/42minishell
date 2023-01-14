/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 00:11:21 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/15 00:16:54 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "env_manager.h"

char	*env_get(t_env_tab *hash_table, char *variable)
{
	t_hash_content	*entry;
	int				bucket;

	bucket = hash_bucket(variable, hash_table->bucket_cnt);
	entry = hash_table_search(hash_table, variable, bucket);
	if (entry)
		return ((char *)entry->content);
	return (NULL);
}