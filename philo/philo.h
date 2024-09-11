/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:57:03 by yunseo            #+#    #+#             */
/*   Updated: 2024/08/16 23:23:41 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define NOT_IN_USE	0
# define IN_USE		1

typedef struct s_input
{
	int				number_of_philo;
	suseconds_t		die;
	suseconds_t		eat;
	suseconds_t		sleep;
	int				number_of_times_must_eat;
}t_input;

typedef struct s_vars
{
	t_input			*input;
	suseconds_t		start_time;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	finish_mutex;
	int				finish;
	pthread_mutex_t	eat_num_mutex;
	int				eat_num;
}t_vars;

typedef struct s_philo
{
	int				id;
	t_vars			*vars;
	pthread_mutex_t	*l_fork_mutex;
	int				*l_fork;
	pthread_mutex_t	*r_fork_mutex;
	int				*r_fork;
	pthread_mutex_t	*eat_cnt_mutex;
	int				eat_cnt;
	pthread_mutex_t	*last_eat_mutex;
	suseconds_t		last_eat;
}t_philo;

// eat -> sleep -> think -> eat -> ...

//	init.c
t_vars		*vars_init(int argc, char **argv);
t_philo		**philos_init(t_vars *vars, int size);

//	philo.c
void		set_philo(t_philo **philos, int size);

// thread.c
void		*start_routine(void *arg);
void		ph_eat(t_philo *philo);
void		ph_sleep(t_philo *philo);
void		ph_think(t_philo *philo);

// utils.c
long		ft_atol(const char *nptr);
suseconds_t	getms(void);

#endif

/*

timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died

*/

/*

int	usleep(useconds_t usec)
int	gettimeofday(struct timeval *tv, struct timezone *tz)

int	pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg)
int	pthread_detach(pthread_t thread)
int pthread_join(pthread_t thread, void **retval)

int	pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr)
int	pthread_mutex_destroy(pthread_mutex_t *mutex)
int	pthread_mutex_lock(pthread_mutex_t *mutex)
int	pthread_mutex_unlock(pthread_mutex_t *mutex)

*/
