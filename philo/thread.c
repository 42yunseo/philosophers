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

	philo = (t_philo *)arg;
	while (1)
	{
		ph_eat(philo);
		ph_sleep(philo);
		ph_think(philo);
	}
	return (NULL);
}

void	ph_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{

	}
	else
	{

	}
}

void	ph_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->vars->print_mutex);
	printf("%ld %d is thinking\n", getms(), philo->id);
	pthread_mutex_unlock(philo->vars->print_mutex);
	usleep(philo->vars->sleep * 1000);
}

void	ph_think(t_philo *philo)
{
	pthread_mutex_lock(philo->vars->print_mutex);
	printf("%ld %d is thinking\n", getms(), philo->id);
	pthread_mutex_unlock(philo->vars->print_mutex);
}
