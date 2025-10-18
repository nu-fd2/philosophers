/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 04:35:23 by oel-mado          #+#    #+#             */
/*   Updated: 2025/10/04 21:17:26 by oel-mado         ###   ########.fr       */
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

int ft_solo(void *data)
{
	(t_data *)data;
	pthread_mutex_lock(data->l_fork);
	print(data, data->phees[0], "da frxita");
	return (check_death(data));
}

int ft_eat(t_data *data)
{
	pthread_mutex_lock(data->m_prnt);
	print(data, data->phees, "eatin");
	usleep(500);
	pthread_mutex_unlock(data->m_prnt);
	return (check_death(data));
}

int ft_eep(t_data *data)
{
	pthread_mutex_lock(data->m_prnt);
	print(data, data->phees, "eepin");
	usleep(500);
	pthread_mutex_unlock(data->m_prnt);
	return (check_death(data));
}

int ft_tweak(t_data *data)
{
	pthread_mutex_lock(data->m_prnt);
	print(data, data->phees, "tweakin");
	usleep(500);
	pthread_mutex_unlock(data->m_prnt);
	return (check_death(data));
}

int ft_act(t_philo *phi)
{
	if (phi->id % 2 == 0)
		usleep(500);
	while (check_death(phi->data))
	{
		pthread_mutex_lock(phi->l_fork);
		print(phi->data, phi, "taked fork");
		pthread_mutex_lock(phi->r_fork);
		print(phi->data, phi, "taked 2th fork");
		ft_eat(phi->data);
		pthread_mutex_unlock(phi->r_fork);
		pthread_mutex_unlock(phi->l_fork);
		ft_eep(phi->data);
		ft_tweak(phi->data);
	}
	return (check_death(phi->data));
}

int ft_moon(t_data *data)
{
	long long t = get_time();
	int i;

	i = 0;
	while (check_death(data))
	{
		while (&(data->phees)[i])
		{
			
			i++;
		}
		
			if (check_death(data))
    			print("%lld %s\n", t - data->strt_tm, "mat");
		else
			usleep(500);
	}
	return (check_death(data));
}

// int phils(t_data *data)
// {
//     int i = 0;

// 	if (data->n_of_phe == 1)
// 		pthread_create(&data->phees[0], NULL, ft_solo, (void *)data);
// 	else
// 	{
// 		while (i < data->n_of_phe)
// 		{
// 			pthread_create(&data->phees[i], NULL, ft_act, (void *)data);
// 			i++;
// 		}
// 	}
// 	pthread_create(&data->moon, NULL, ft_moon, (void *)data);
// }

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
    // phils(data);
	return (0);
}
