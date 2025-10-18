/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:26:35 by oel-mado          #+#    #+#             */
/*   Updated: 2025/10/18 02:43:09 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_death(t_data *data)
{
    pthread_mutex_lock(data->m_dead);
    if (data->f_dead)
    {
        pthread_mutex_unlock(data->m_dead);
        return (1);
    }
    pthread_mutex_unlock(data->m_dead);
    return (0);
}

long long get_time()
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int print(t_data *data, int philo, char *act)
{
    pthread_mutex_lock(data->m_print);
    if (!check_death(data))
        printf("%lld %d %s\n", get_time() - data->strt_tm, philo, act);
    pthread_mutex_unlock(data->m_print);
    return (check_death(data));
}

void *ts_one(void *ts)
{
    t_philo *philo;

    philo = (t_philo *)ts;
    act_tweak(philo);
    pthread_mutex_lock(philo->l_fork);
    print(philo->data, philo->id, "da 1st fork");
    pthread_mutex_unlock(philo->l_fork);
    usleep(philo->data->t_to_die * 1000);
    return (NULL);
}

void *ts_routin(void *ts)
{
    t_philo *philo;

    philo = (t_philo *)ts;
    if (philo->id % 2)
        usleep(500);
    while (!check_death)
    {
        if (act_tweak(philo))
            return NULL;
        if (act_eat(philo))
            return NULL;
        if (act_eep(philo))
            return NULL;
    }
    return (NULL);
}

int philo(t_data *data)
{
    int i;

    i = 0;
    if (data->n_of_phe == 1)
        pthread_create((&data->philo)[i]->thread, NULL, ts_one, (void *)&(data->philo)[i]);
    while (i < data->n_of_phe)
    {
        pthread_create((&data->philo)[i]->thread, NULL, ts_routin, (void *)&(data->philo)[i]);
        i++;
    }
    pthread_create(data->monitor, NULL, ts_monitor, (void *)&data);
	while (!check_death(data))
	{
		i = 0;
		while (!check_death(data) && i < data->n_of_phe)
			pthread_join(&data->philo->thread[i++], NULL);
	}
	pthread_join(data->monitor, NULL);
    return 0;
}
