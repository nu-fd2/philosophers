#include "philo.h"

int main(int ac, char **av)
{
	s_data	data;

	if (ac == 5 || ac == 6)
	{
		data.n_of_philo = ft_atoi(av[1]);
		data.t_to_die = ft_atoi(av[2]);
		data.t_to_eat = ft_atoi(av[3]);
		data.t_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			data.n_of_t_each_philo_must_eat = ft_atoi(av[5]);
		else
			data.n_of_t_each_philo_must_eat = -1;
		printf("n_of_philo = %d\n", data.n_of_philo);
		printf("t_to_die = %d\n", data.t_to_die);
		printf("t_to_eat = %d\n", data.t_to_eat);
		printf("t_to_sleep = %d\n", data.t_to_sleep);
		printf("n_of_t_each_philo_must_eat = %d\n", data.n_of_t_each_philo_must_eat);
	}
	return (0);
}
