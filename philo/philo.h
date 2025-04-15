#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void 	is_error(void);
void	valid_args(char **av);

typedef	struct t_philo
{
	int					id;
	pthread_t			trd;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	s_philo				*next;
	s_philo				*prev;
}						s_philo;

#endif //PHILO_H
