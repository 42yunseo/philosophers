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
		if (detect_finish(vars) == FINISH)
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
		while (detect_finish(philo->vars) != FINISH)
			usleep(1000);
		return ;
	}
	pthread_mutex_lock(fork_mutex);
	if (detect_finish(philo->vars) == FINISH)
		return ;
	(*fork)++;
	ph_print(philo->vars, philo->id, FORK_MSG);
}

void	ph_eat(t_philo *philo)
{
	suseconds_t	cur_time;

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
	if (detect_finish(philo->vars) == FINISH)
	{
		ph_put_down_forks(philo);
		return ;
	}
	ph_print(philo->vars, philo->id, EAT_MSG);
	update_eat(philo);
	pthread_mutex_lock(philo->last_eat_mutex);
	cur_time = philo->last_eat;
	pthread_mutex_unlock(philo->last_eat_mutex);
	ft_sleep(philo->vars, cur_time, philo->vars->input->eat);
	ph_put_down_forks(philo);
}

void	ph_sleep(t_philo *philo)
{
	suseconds_t	cur_time;

	if (detect_finish(philo->vars) == FINISH)
		return ;
	cur_time = get_cur_ms(philo->vars);
	ph_print(philo->vars, philo->id, SLEEP_MSG);
	ft_sleep(philo->vars, cur_time, philo->vars->input->sleep);
}

void	ph_think(t_philo *philo)
{
	if (detect_finish(philo->vars) == FINISH)
		return ;
	ph_print(philo->vars, philo->id, THINK_MSG);
}
