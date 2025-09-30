/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:49:00 by oel-mado          #+#    #+#             */
/*   Updated: 2025/09/30 08:23:03 by oel-mado         ###   ########.fr       */
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

int check_death(t_data *data);
long long get_time();
int print(t_data *data, int philo, char *act);

int philo(t_data *data);

void clean(t_data *data);


typedef struct s_philo
{
	int				id;
	pthread_t		trd; // thread

	long long		lst_m; // fo9ax a5ir mra kla
	int				m_etn; // x7al kla

	pthread_mutex_t	*m_etn; // lock x7al mvn mra kla

	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;

	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				n_of_phe;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_eep;
	int				n_mus_et;

	long long		strt_tm;

	bool			f_dead;
	pthread_mutex_t *m_dead;

	pthread_mutex_t *m_prnt;

	t_philo			*phees;
	pthread_mutex_t	*forks;

	pthread_t		*moon;
}					t_data;

#endif //PHILO_H
