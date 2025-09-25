/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:47:27 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/25 05:52:13 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	sep(t_data *data, char **av, bool s)
{
	int	i;

	i = 0;
	data->n_of_philo = ft_atoi(av[1]);
	data->t_to_die = ft_atoi(av[2]);
	data->t_to_eat = ft_atoi(av[3]);
	data->t_to_sleep = ft_atoi(av[4]);
	if (s)
		data->n_of_t_each_philo_must_eat = ft_atoi(av[5]);
	else
		data->n_of_t_each_philo_must_eat = -1;
	if (data->n_of_philo <= 0 || data->t_to_die <= 0
    	|| data->t_to_eat <= 0 || data->t_to_sleep <= 0
    	|| (s && data->n_of_t_each_philo_must_eat <= 0))
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_of_philo);
	if (!(data->forks))
		is_error("malloc filat", data->forks, NULL);
	data->philos = malloc(sizeof(t_philo) * data->n_of_philo);
	if (!(data->philos))
		is_error("malloc tanya filat", data->forks, data->philos);
	while (i < data->n_of_philo)
		pthread_mutex_init(&data->forks[i++], NULL);
	return (0);
}

int	main(int ac, char **av)
{
	t_data			data;

	if (ac == 5 || ac == 6)
	{
		if (sep(&data, av, ac - 5))
			return (0);
	}
	return (0);
}
