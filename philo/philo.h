/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fd2 <fd2@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 00:49:00 by fd2               #+#    #+#             */
/*   Updated: 2025/04/20 00:55:45 by fd2              ###   ########.fr       */
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
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_philo;

typedef struct s_data
{
	int				n_of_philo;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				n_of_t_each_philo_must_eat;
	pthread_t		*philos;
	pthread_mutex_t	*forks;
}					t_data;

#endif //PHILO_H
