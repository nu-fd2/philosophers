/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 06:39:10 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/30 07:37:25 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_data			*data;

    data = malloc(sizeof(t_data) * 1);
	if (ac == 5 || ac == 6)
	{
		if (datating(data, av, ac - 5))
			return (0);
	}
    philo(data);
    cl_ean(data);
	return (0);
}
