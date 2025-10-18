/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 06:38:07 by oel-mado          #+#    #+#             */
/*   Updated: 2025/10/04 21:11:49 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// int act(t_philo *eep)
// {
// 	pthread_mutex_lock(&eep->data->m_prnt);
// 	while (1)
// 	{
// 		usleep(10000);
// 		write(1, ".", 1);
// 		write(1, "\n", 1);
// 	}
// 	pthread_mutex_unlock(&eep->data->m_prnt);
// }

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
    pthread_mutex_lock(data->m_prnt);
    if (!check_death)
        printf("%lld %d %s\n", get_time() - data->strt_tm, philo, act);
    pthread_mutex_unlock(data->m_prnt);
}
