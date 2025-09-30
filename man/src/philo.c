/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:47:27 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/30 08:25:31 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void clean(t_data *data)
{
	int i;

	i = 0;
	while (i < data->n_of_phe)
		free(data->phees[i++]);
	i = 0;
	while (i < data->n_of_phe)
		free(data->forks[i++]);
	free(data);
}

int philo(t_data *data)
{
	int i;

	i = 0;
	while (i < data->n_of_phe)
	{
		if (pthread_create(&((data)->phees)[i]->trd, NULL, act, (data->phees)[i]) != 0)
			is_error("cant creat thread", NULL, NULL);
		i++;
	}

	//---

	while (!check_death(data))
	{
		i = 0;
		while (!check_death(data))
			pthread_join(((data->phees)->trd)[i++], NULL);
	}
	pthread_join(data->moon, NULL);
}
