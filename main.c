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

void	print_cur_time(struct timeval *start)
{
	struct timeval	*cur;

	cur = (struct timeval *)malloc(sizeof(struct timeval));
	if (cur == NULL)
		exit(EXIT_FAILURE);
	gettimeofday(cur, NULL);
	printf("timestamp : %ld\n", (cur->tv_sec - start->tv_sec) * 1000000 + (cur->tv_usec - start->tv_usec));
}

int	main(int argc, char **argv)
{
	t_vars			*vars;
	struct timeval	*tv;

	if (argc < 5 || argc > 6)
		return (0);
	tv = (struct timeval *)malloc(sizeof(struct timeval));
	if (tv == NULL)
		exit(EXIT_FAILURE);
	gettimeofday(tv, NULL);
	vars = vars_init(argc, argv);
	usleep(100);
	print_cur_time(tv);
}
