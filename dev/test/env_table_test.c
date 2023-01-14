/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_table_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 23:13:43 by hyeyukim          #+#    #+#             */
/*   Updated: 2023/01/14 23:26:56 by hyeyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_manager.h"

void	show_hash_table(t_hash_table *table);

int	main(int argc, char **argv, char **envp)
{
	t_env_tab	*table;

	argc++;
	argv++;
	initialize_env_table(&table, envp);
	show_hash_table(table);
	hash_table_destroy(table);
}
