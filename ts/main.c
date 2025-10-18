/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 08:01:21 by oel-mado          #+#    #+#             */
/*   Updated: 2025/10/14 16:33:16 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int prnt_msg(int ac)
{
    if (ac < 5 || ac > 6)
        ;
    return 1;
}

int main(int ac, char **av)
{
    t_data *data;

    if (ac < 5 || ac > 6)
    {
        write(2, "nah\n", 4);
        return 1;
    }
    data = calloc(1 , sizeof(t_data));
    pars(data, ac, av, ac - 5);
    if (init(data))
        return (free(data), 1);
    philo(data);
    clean(data);
    return 0;
}
