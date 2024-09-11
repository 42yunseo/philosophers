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
		pthread_mutex_lock(&vars->finish_mutex);
		if (vars->finish == FINISH)
		{
			pthread_mutex_unlock(&vars->finish_mutex);
			break ;
		}
		pthread_mutex_unlock(&vars->finish_mutex);
		ph_eat(philo);
		ph_sleep(philo);
		ph_think(philo);
	}
	return (NULL);
}

void	ph_eat(t_philo *philo)
{
	//suseconds_t	start_time;

	//start_time = philo->vars->start_time;
	if (philo->id % 2 == 0)
	{

	}
	else
	{

	}
}

void	ph_sleep(t_philo *philo)
{
	suseconds_t	start_time;
	suseconds_t	cur_time;
	suseconds_t	target_time;

	start_time = philo->vars->start_time;
	cur_time = getms();
	target_time = cur_time + philo->vars->input->sleep;
	pthread_mutex_lock(&philo->vars->print_mutex);
	printf("%ld - %ld = %ld\n", cur_time, start_time, cur_time - start_time);
	printf("%ld %d is sleeping\n", cur_time - start_time, philo->id);
	pthread_mutex_unlock(&philo->vars->print_mutex);
	usleep(philo->vars->input->sleep / 2);
	while (getms() < target_time)
		usleep(100);
	//usleep(philo->vars->input->sleep * 1000);
}

void	ph_think(t_philo *philo)
{
	suseconds_t	start_time;

	start_time = philo->vars->start_time;
	pthread_mutex_lock(&philo->vars->print_mutex);
	printf("%ld %d is thinking\n", getms() - start_time, philo->id);
	pthread_mutex_unlock(&philo->vars->print_mutex);
}
