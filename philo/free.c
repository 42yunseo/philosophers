/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:45:45 by yunseo            #+#    #+#             */
/*   Updated: 2024/08/16 23:17:53 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	vars_free(t_vars *vars)
{
	free(vars->input);	
	pthread_mutex_destroy(&vars->print_mutex);
	pthread_mutex_destroy(&vars->finish_mutex);
	pthread_mutex_destroy(&vars->eat_num_mutex);
	free(vars);
}

void	philo_free(t_philo *philo)
{
	free(philo->l_fork);
	pthread_mutex_destroy(philo->l_fork_mutex);
	pthread_mutex_destroy(philo->eat_cnt_mutex);
	pthread_mutex_destroy(philo->last_eat_mutex);
	free(philo);
}

void	philos_free(t_philo **philos, int size)
{
	int	i;

	i = 0;
	while (i < size)
		philo_free(philos[i++]);
	free(philos);
}

void	free_all(t_vars *vars, t_philo **philos, pthread_t *ph_thread)
{
	int	size;

	size = vars->input->number_of_philo;
	vars_free(vars);
	philos_free(philos, size);
}