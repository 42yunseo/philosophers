/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:54:08 by yunseo            #+#    #+#             */
/*   Updated: 2024/09/15 17:54:09 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	detect_finish(t_vars *vars)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&vars->finish_mutex);
	if (vars->finish == FINISH)
		ret = FINISH;
	pthread_mutex_unlock(&vars->finish_mutex);
	return (ret);
}

void	detect_starvation(t_vars *vars, t_philo **philos)
{
	int	i;
	int	size;

	i = 0;
	size = vars->input->number_of_philo;
	while (i < size)
	{
		if (detect_finish(vars) == FINISH)
			break ;
		pthread_mutex_lock(philos[i]->last_eat_mutex);
		if (get_cur_ms(vars) - philos[i]->last_eat > vars->input->die)
		{
			ph_print(vars, i + 1, DIED_MSG);
			pthread_mutex_lock(&vars->finish_mutex);
			vars->finish = FINISH;
			pthread_mutex_unlock(&vars->finish_mutex);
		}
		pthread_mutex_unlock(philos[i]->last_eat_mutex);
		i++;
	}
}

void	detect_eat_cnt(t_vars *vars)
{
	pthread_mutex_lock(&vars->eat_num_mutex);
	if (vars->eat_num == vars->input->number_of_philo)
	{
		pthread_mutex_lock(&vars->finish_mutex);
		vars->finish = FINISH;
		pthread_mutex_unlock(&vars->finish_mutex);
	}
	pthread_mutex_unlock(&vars->eat_num_mutex);
}
