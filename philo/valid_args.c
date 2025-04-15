#include "philo.h"

void	valid_args(char **av)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (av[i])
	{
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				is_error();
			j++;
		}
		i++;
	}
}
