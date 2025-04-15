#include "philo.h"

int main(int ac, char **av)
{
	int   i;

	i = 0;
	// pthread_init();
	// pthread_create();
	if (ac == 4 || ac == 5)
	{
		valid_args(av);
		printf("all good\n");
	}
	while (i < ac)
		printf("%s\n", av[i++]);
	// pthread_exit();
	return (0);
}

