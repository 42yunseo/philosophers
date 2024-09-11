/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:38:19 by yunseo            #+#    #+#             */
/*   Updated: 2024/09/11 10:38:20 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_philo(t_philo **philos, int size)
{
	int	i;
	int	r_idx;

	i = 0;
	while (i < size)
	{
		pthread_mutex_init(philos[i]->l_fork_mutex, NULL);
		*philos[i]->l_fork = NOT_IN_USE;
		pthread_mutex_init(philos[i]->eat_cnt_mutex, NULL);
		pthread_mutex_init(philos[i]->last_eat_mutex, NULL);
		i++;
	}
	if (size != 1)
	{
		i = 0;
		while (i < size)
		{
			r_idx = (size + i - 1) % size;
			philos[i]->r_fork = philos[r_idx]->l_fork;
			philos[i]->r_fork_mutex = philos[r_idx]->l_fork_mutex;
			i++;
		}
	}
}
