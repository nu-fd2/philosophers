/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 06:36:21 by oel-mado          #+#    #+#             */
/*   Updated: 2025/10/14 16:42:43 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int pars(t_data *data, int ac, char **av, int s)
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
	data->m_forks = malloc(sizeof(pthread_mutex_t) * data->n_of_phe);
	if (!(data->m_forks))
		is_error("malloc 5rat", data->m_forks, NULL);
	data->philo = malloc(sizeof(t_philo *) * data->n_of_phe);
	if (!(data->philo))
		is_error("2th malloc 5rat", data->m_forks, data->philo);
}
