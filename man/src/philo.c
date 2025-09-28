/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:47:27 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/27 05:50:49 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_ool			tool;

	if (ac == 5 || ac == 6)
	{
		if (sep(&tool, av, ac - 5))
			return (0);
	}


	return (0);
}

int act(t_philo *eep)
{
	pthread_mutex_lock(&eep->tool->m_prnt);
	while (1)
	{
		usleep(10000);
		write(1, ".", 1);
		write(1, "\n", 1);
	}
	pthread_mutex_unlock(&eep->tool->m_prnt);
}
