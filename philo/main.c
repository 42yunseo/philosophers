/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 23:17:36 by yunseo            #+#    #+#             */
/*   Updated: 2024/08/16 23:17:53 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_cur_time(struct timeval start, const char *msg)
{
	struct timeval	cur;
	suseconds_t		diff_time;

	gettimeofday(&cur, NULL);
	printf("sec : %ld, usec : %ld\n", cur.tv_sec - start.tv_sec, cur.tv_usec - start.tv_usec);
	diff_time = (cur.tv_sec - start.tv_sec) * 1000 + (cur.tv_usec - start.tv_usec) / 1000;
	printf("%ld %s\n", diff_time, msg);
}

void	*start_routine(void *arg)
{
	struct timeval	tv;

	tv = ((t_vars *)arg)->start_time;
	print_cur_time(tv, "start");
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_vars		*vars;
	pthread_t	**philo;

	if (argc != 5 && argc != 6)
		return (0);
	vars = vars_init(argc, argv);
	philo = philo_init(vars);
	sleep(5);
}
