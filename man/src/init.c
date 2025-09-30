/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 04:35:23 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/30 14:50:03 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int mutexin(t_data *data)
{
    int i;

    i = 0;
    while (i < data->n_of_phe)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
    pthread_mutex_init(&data->m_prnt, NULL);
    pthread_mutex_init(&data->m_dead, NULL);
}

int oneer(void *data)
{
	
}


int phils(t_data *data)
{
    int i = 0;

	if (data->n_of_phe == 1)
		pthread_create(&data->phees[0], NULL, oneer, (void *)data);
	else
	{
		while (i < data->n_of_phe)
		{
			pthread_create(&data->phees[i], NULL, root_n, (void *)data);
			i++;
		}
	}
	pthread_create(&data->moon, NULL, schism, (void *)data);
}

int datating(t_data *data, char **av, bool s)
{
	data->n_of_phe = ft_atoi(av[1]);
	data->t_to_die = ft_atoi(av[2]);
	data->t_to_eat = ft_atoi(av[3]);
	data->t_to_eep = ft_atoi(av[4]);
	if (s)
		data->n_mus_et = ft_atoi(av[5]);
	else
		data->n_mus_et = -1;
	if (data->n_of_phe <= 0 || data->t_to_die <= 0
    	|| data->t_to_eat <= 0 || data->t_to_eep <= 0
    	|| (s && data->n_mus_et <= 0))
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_of_phe);
	if (!(data->forks))
		is_error("malloc 5rat", data->forks, NULL);
	data->phees = malloc(sizeof(t_philo) * data->n_of_phe);
	if (!(data->phees))
		is_error("2th malloc 5rat", data->forks, data->phees);
    mutexin(data);
    phils(data);
	return (0);
}
