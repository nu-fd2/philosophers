/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:34:12 by oel-mado          #+#    #+#             */
/*   Updated: 2025/10/15 01:53:05 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int (i), (n);
	i = 0;
	n = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '\0')
		is_error("arg is empty", NULL, NULL);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_error("arg is negative", NULL, NULL);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i++] - '0');
		if (n < 0)
			is_error("arg is too big", NULL, NULL);
	}
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] != '\0')
		is_error("arg is not a number", NULL, NULL);
	return (n);
}

int cln(t_data *data, int i)
{
    int j;

    j = 0;
    while (j < i)
    {
        free((&data->philo)[j]);
        j++;
    }
    return 1;
}

int int_philo(t_data *data)
{
    int i;

    i = 0;
    while (i < data->n_of_phe)
    {
        (&data->philo)[i] = malloc(sizeof(t_philo) * 1);
        if (!(&data->philo)[i])
            return (cln(data, i));
        data->philo->id = i + 1;
        data->philo->last_m = data->strt_tm;
        data->philo->n_etn = 0;
        data->philo->data = data;
        data->philo->r_fork = (&data->m_forks)[i % 5];
        data->philo->l_fork = (&data->m_forks)[(i + 1) % 5];
        i++;
    }
    return 0;
}

int init(t_data *data)
{
    int i;

    i = 0;
    while (i < data->n_of_phe)
    {
        pthread_mutex_init(&data->m_forks[i], NULL);
        i++;
    }
    pthread_mutex_init(&data->m_print, NULL);
    pthread_mutex_init(&data->m_dead, NULL);
    return int_philo(data);
}
