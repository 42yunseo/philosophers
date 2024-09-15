/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:33:29 by yunseo            #+#    #+#             */
/*   Updated: 2024/09/06 17:33:30 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_routine(void *arg)
{
	t_philo	*philo;
	t_vars	*vars;

	philo = (t_philo *)arg;
	vars = philo->vars;
	while (1)
	{
		if (finish_detect(vars) == FINISH)
			break ;
		ph_eat(philo);
		ph_sleep(philo);
		ph_think(philo);
	}
	return (NULL);
}

void	ph_take_fork(t_philo *philo, int dir)
{
	pthread_mutex_t	*fork_mutex;
	int				*fork;

	if (dir == L_FORK)
	{
		fork_mutex = philo->l_fork_mutex;
		fork = philo->l_fork;
	}
	else
	{
		fork_mutex = philo->r_fork_mutex;
		fork = philo->r_fork;
	}
	if (fork_mutex == NULL)
	{
		while (finish_detect(philo->vars) != FINISH)
			usleep(1000);
		return ;
	}
	pthread_mutex_lock(fork_mutex);
	fork++;
	ph_print(philo->vars, philo->id, FORK_MSG);
}

void	ph_eat(t_philo *philo)
{
	suseconds_t	cur_time;

	if (finish_detect(philo->vars) == FINISH)
		return ;
	if (philo->id % 2 != 0)
	{
		ph_take_fork(philo, L_FORK);
		ph_take_fork(philo, R_FORK);
	}
	else
	{
		ph_take_fork(philo, R_FORK);
		ph_take_fork(philo, L_FORK);
	}
	if (finish_detect(philo->vars) == FINISH)
	{
		ph_put_down_forks(philo);
		return ;
	}
	pthread_mutex_lock(philo->eat_cnt_mutex);
	philo->eat_cnt++;
	if (philo->eat_cnt == philo->vars->input->number_of_times_must_eat)
	{
		pthread_mutex_lock(&philo->vars->eat_num_mutex);
		philo->vars->eat_num++;
		pthread_mutex_unlock(&philo->vars->eat_num_mutex);
	}
	cur_time = getms();
	pthread_mutex_unlock(philo->eat_cnt_mutex);
	pthread_mutex_lock(philo->last_eat_mutex);
	philo->last_eat = cur_time;
	pthread_mutex_unlock(philo->last_eat_mutex);
	ph_print(philo->vars, philo->id, EAT_MSG);
	ft_sleep(cur_time, philo->vars->input->eat);
	ph_put_down_forks(philo);
}

void	ph_sleep(t_philo *philo)
{
	suseconds_t	cur_time;

	if (finish_detect(philo->vars) == FINISH)
		return ;
	cur_time = getms();
	ph_print(philo->vars, philo->id, SLEEP_MSG);
	ft_sleep(cur_time, philo->vars->input->sleep);
}

void	ph_think(t_philo *philo)
{
	if (finish_detect(philo->vars) == FINISH)
		return ;
	ph_print(philo->vars, philo->id, THINK_MSG);
}
