/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 08:18:19 by oel-mado          #+#    #+#             */
/*   Updated: 2025/10/18 02:14:08 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int eep(t_data *data, long long tm)
{
    long long t;

    t = get_time();
    while (get_time() - t < tm)
    {
        if (check_death(data))
            return 1;
        usleep(500);
    }
    return (check_death(data));
}

int act_eep(t_philo* philo)
{
    if (!check_death(philo->data))
        print(philo->data, philo->id, "eepin");
    return (eep(philo->data, philo->data->t_to_eep));
}

int act_eat(t_philo* philo)
{
    pthread_mutex_lock(philo->l_fork);
    if (print(philo->data, philo->id, "da 1st fork"))
        return (pthread_mutex_unlock(philo->l_fork), 1);
    pthread_mutex_lock(philo->r_fork);
    if (print(philo->data, philo->id, "da 2th fork"))
        return (pthread_mutex_unlock(philo->r_fork),
            pthread_mutex_unlock(philo->l_fork), 1);
    pthread_mutex_lock(philo->m_etn);
    if (print(philo->data, philo->id, "eatin"))
        return (pthread_mutex_unlock(philo->m_etn),
            pthread_mutex_unlock(philo->r_fork),
            pthread_mutex_unlock(philo->l_fork), 1);
    philo->n_etn++;
    philo->last_m = get_time();
    if (eep(philo->data, philo->data->t_to_eat))
        return (pthread_mutex_unlock(philo->m_etn),
            pthread_mutex_unlock(philo->r_fork),
            pthread_mutex_unlock(philo->l_fork), 1);
    return (pthread_mutex_unlock(philo->m_etn),
        pthread_mutex_unlock(philo->r_fork),
        pthread_mutex_unlock(philo->l_fork), check_death(philo->data));
}

int act_tweak(t_philo* philo)
{
    print(philo->data, philo->id, "tweakin");
    return (check_death(philo->data));
}
