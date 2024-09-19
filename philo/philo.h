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

# define FINISH		1

# define L_FORK		0
# define R_FORK		1

# define FORK_MSG	"has taken a fork"
# define EAT_MSG	"is eating"
# define SLEEP_MSG	"is sleeping"
# define THINK_MSG	"is thinking"
# define DIED_MSG	"is died"

typedef struct s_input
{
	int	number_of_philo;
	int	die;
	int	eat;
	int	sleep;
	int	number_of_times_must_eat;
}	t_input;

typedef struct s_vars
{
	t_input			*input;
	suseconds_t		start_time;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	finish_mutex;
	int				finish;
	pthread_mutex_t	eat_num_mutex;
	int				eat_num;
}	t_vars;

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
}	t_philo;

// eat -> sleep -> think -> eat -> ...

//	init.c
t_vars		*vars_init(int argc, char **argv);
t_philo		**philos_init(t_vars *vars);
pthread_t	*thread_init(int size);

//	philo.c
void		set_philo(t_philo **philos, int size);

// thread.c
void		*start_routine(void *arg);
void		ph_take_fork(t_philo *philo, int dir);
void		ph_eat(t_philo *philo);
void		ph_sleep(t_philo *philo);
void		ph_think(t_philo *philo);

// thread_utils.c
void		ph_print(t_vars *vars, int id, const char *msg);
void		ft_sleep(t_vars *vars, suseconds_t cur_time, suseconds_t msec);
void		ph_put_down_forks(t_philo *philo);
suseconds_t	update_last_eat(t_philo *philo);
void		update_eat_cnt(t_philo *philo);

// detect.c
int			detect_finish(t_vars *vars);
void		detect_starvation(t_vars *vars, t_philo **philos);
void		detect_eat_cnt(t_vars *vars);

// utils.c
int			ft_isdigit(int c);
long		ft_atol(const char *nptr);
suseconds_t	getms(void);
suseconds_t	get_cur_ms(t_vars *vars);

void		free_all(t_vars *vars, t_philo **philos, pthread_t *ph_thread);

#endif
