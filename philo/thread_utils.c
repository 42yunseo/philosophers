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

void	ft_sleep(suseconds_t cur_time, suseconds_t msec)
{
	suseconds_t	target_time;

	target_time = cur_time + msec;
	// while (msec > 3)
	// {
	// 	usleep(msec * 1000);
	// 	msec = msec >> 1;
	// }
	while (getms() < target_time)
		usleep(100);
}
