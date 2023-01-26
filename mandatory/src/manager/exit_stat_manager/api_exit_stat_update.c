#include "exit_stat_manager_internal.h"

int	exit_stat_update(int new_stat)
{
	return (exit_stat_manager(EXIT_STAT_UPDATE, new_stat));
}
