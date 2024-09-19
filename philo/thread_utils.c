/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:18:55 by yunseo            #+#    #+#             */
/*   Updated: 2024/09/14 16:18:56 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_print(t_vars *vars, int id, const char *msg)
{
	pthread_mutex_lock(&vars->print_mutex);
	printf("%ld %d %s\n", get_cur_ms(vars), id, msg);
	pthread_mutex_unlock(&vars->print_mutex);
}

void	ft_sleep(t_vars *vars, suseconds_t start_time, suseconds_t msec)
{
	suseconds_t	target_time;

	target_time = start_time + msec;
	while (get_cur_ms(vars) < target_time)
	{
		if (detect_finish(vars) == FINISH)
			return ;
		usleep(100);
	}
}

void	ph_put_down_forks(t_philo *philo)
{
	if (philo->l_fork != NULL)
	{
		(*philo->l_fork)--;
		pthread_mutex_unlock(philo->l_fork_mutex);
	}
	if (philo->r_fork != NULL)
	{
		(*philo->r_fork)--;
		pthread_mutex_unlock(philo->r_fork_mutex);
	}
}

suseconds_t	update_last_eat(t_philo *philo)
{
	suseconds_t	cur_time;

	pthread_mutex_lock(philo->last_eat_mutex);
	cur_time = get_cur_ms(philo->vars);
	philo->last_eat = cur_time;
	pthread_mutex_unlock(philo->last_eat_mutex);
	return (cur_time);
}

void	update_eat_cnt(t_philo *philo)
{
	pthread_mutex_lock(philo->eat_cnt_mutex);
	philo->eat_cnt++;
	if (philo->eat_cnt == philo->vars->input->number_of_times_must_eat)
	{
		pthread_mutex_lock(&philo->vars->eat_num_mutex);
		philo->vars->eat_num++;
		pthread_mutex_unlock(&philo->vars->eat_num_mutex);
	}
	pthread_mutex_unlock(philo->eat_cnt_mutex);
}
