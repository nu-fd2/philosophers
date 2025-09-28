/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:49:00 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/25 04:32:24 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <time.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

void	is_error(char *str, void *p1, void *p2);
int		ft_atoi(const char *str);

typedef struct s_philo
{
	int				id;
	pthread_t		trd;

	int				lst_m;
	int				m_etn;

	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;

	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				n_of_philo;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				n_of_t_each_philo_must_eat;

	bool			f_dead;

	int				strt_tm;
	pthread_mutex_t *prnt_lock;

	t_philo			*philos;
	pthread_mutex_t	*forks;
}					t_data;

#endif //PHILO_H
