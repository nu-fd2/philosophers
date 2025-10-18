/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 02:52:07 by oel-mado          #+#    #+#             */
/*   Updated: 2025/10/18 02:57:23 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ts_clean(t_data *data)
{
    int i;

    i = 0;
    pthread_mutex_destroy(data->m_dead);
    pthread_mutex_destroy(data->m_print);
    while(i < data->n_of_phe)
    {
        pthread_mutex_destroy((&data->philo)[i]->m_etn);
        pthread_mutex_destroy((&data->philo)[i]->l_fork);
        free()
        i++;
    }
}
