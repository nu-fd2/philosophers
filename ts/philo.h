/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 07:59:41 by oel-mado          #+#    #+#             */
/*   Updated: 2025/10/18 02:43:14 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <time.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

typedef struct s_philo
{
    int id;
    pthread_t       thread;

    long            last_m;
    int             n_etn;

    pthread_mutex_t *m_etn;
    pthread_mutex_t *l_fork;
    pthread_mutex_t *r_fork;

    struct s_data   *data;
}           t_philo;

typedef struct s_data
{
	int				n_of_phe;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_eep;
	int				n_mus_et;

	long            strt_tm;

    int             f_dead;
	pthread_mutex_t *m_dead;

	pthread_mutex_t *m_print;
    
    t_philo *philo;
	pthread_mutex_t *m_forks;

    pthread_t       *monitor;
}           t_data;

int pars(t_data *data, int ac, char **av, int s);

int act_eep(t_philo* philo);
int act_eat(t_philo* philo);
int act_tweak(t_philo* philo);

int check_death(t_data *data);

int print(t_data *data, int philo, char *act);

long long get_time();

int eep(t_data *data, long long tm);

int act_eep(t_philo* philo);
int act_eat(t_philo* philo);
int act_tweak(t_philo* philo);

void *ts_monitor(void *data);

#endif // PHILO_H
