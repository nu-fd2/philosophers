#include "philo.h"

void	is_error(char *str, void *p1, void *p2)
{
	if (str)
		printf("\e[1;31m%s\e[0m\n", str);
	if (p1)
		free(p1);
	if (p2)
		free(p2);
	write(2, "\e[1;31mError\e[0m\n", 17);
	exit(1);
}
