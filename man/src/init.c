/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 04:35:23 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/27 06:25:41 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int myotixsin(t_ool *tool)
{
    int i;

    i = 0;
    while (i < tool->n_of_phe)
    {
        pthread_mutex_init(&tool->forks[i], NULL);
        i++;
    }
    pthread_mutex_init(&tool->m_prnt, NULL);
    pthread_mutex_init(&tool->m_dead, NULL);
}

int oneer(void *tool)
{
	
}

int	schism(void *tool);

int philowing(t_ool *tool)
{
    int i = 0;

	if (tool->n_of_phe == 1)
		pthread_create(&tool->phees[0], NULL, oneer, (void *)tool);
	else
	{
		while (i < tool->n_of_phe)
		{
			pthread_create(&tool->phees[i], NULL, root_n, (void *)tool);
			i++;
		}
	}
	pthread_create(&tool->pneuma, NULL, schism, (void *)tool);
}

int toolting(t_ool *tool, char **av, bool s)
{
	tool->n_of_phe = ft_atoi(av[1]);
	tool->t_to_die = ft_atoi(av[2]);
	tool->t_to_eat = ft_atoi(av[3]);
	tool->t_to_eep = ft_atoi(av[4]);
	if (s)
		tool->n_mus_et = ft_atoi(av[5]);
	else
		tool->n_mus_et = -1;
	if (tool->n_of_phe <= 0 || tool->t_to_die <= 0
    	|| tool->t_to_eat <= 0 || tool->t_to_eep <= 0
    	|| (s && tool->n_mus_et <= 0))
		return (1);
	tool->forks = malloc(sizeof(pthread_mutex_t) * tool->n_of_phe);
	if (!(tool->forks))
		is_error("malloc 5rat", tool->forks, NULL);
	tool->phees = malloc(sizeof(t_philo) * tool->n_of_phe);
	if (!(tool->phees))
		is_error("2th malloc 5rat", tool->forks, tool->phees);
    myotixsin(tool);
    philowing(tool);
	return (0);
}
