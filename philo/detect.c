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

int	finish_detect(t_vars *vars)
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

	//printf("detect_starvation call\n");
	i = 0;
	size = vars->input->number_of_philo;
	while (i < size)
	{
		pthread_mutex_lock(philos[i]->last_eat_mutex);
		if (philos[i]->last_eat + vars->input->die < get_cur_ms(vars))
		{
			ph_print(vars, i + 1, DIED_MSG);
			pthread_mutex_lock(&vars->finish_mutex);
			vars->finish = FINISH;
			pthread_mutex_unlock(&vars->finish_mutex);
			pthread_mutex_unlock(philos[i]->last_eat_mutex);
		}
		pthread_mutex_unlock(philos[i]->last_eat_mutex);
		i++;
	}
}
