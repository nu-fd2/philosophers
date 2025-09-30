/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:47:27 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/30 12:25:17 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void p_clean(t_data *data)
{
	int i;

	i = 0;
	while (i < data->n_of_phe)
		free(&data->phees[i++]);
	i = 0;
	while (i < data->n_of_phe)
		free(&data->forks[i++]);
	free(data);
}

int philo(t_data *data)
{
	int i;

	i = 0;
	while (i < data->n_of_phe)
	{
		if (pthread_create((&data->phees[i])->trd, NULL, act, &data->phees[i]) != 0)
			is_error(data, "cant creat thread", 1);
		i++;
	}

	if (pthread_create((&data->phees[i])->trd, NULL, act, &data->phees[i]) != 0)
		is_error(data, "cant creat thread", 0);

	while (!check_death(data))
	{
		i = 0;
		while (!check_death(data))
			pthread_join(&data->phees->trd[i++], NULL);
	}
	pthread_join(data->moon, NULL);
}
