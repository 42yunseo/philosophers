/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 23:30:34 by yunseo            #+#    #+#             */
/*   Updated: 2024/08/16 23:31:05 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_vars	*vars_init(int argc, char **argv)
{
	t_vars	*vars;
	int		i;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (vars == NULL)
		exit(EXIT_FAILURE);
	memset(vars, -1, sizeof(t_vars));
	i = 0;
	vars->number_of_philo = atoi(argv[1]);
	vars->die = ft_atol(argv[2]);
	vars->eat = ft_atol(argv[3]);
	vars->sleep = ft_atol(argv[4]);
	if (argc == 6)
		vars->number_of_times_must_eat = atoi(argv[5]);
	return (vars);
}

pthread_t	**philo_init(t_vars *vars)
{
	pthread_t	**philos;
	int			i;

	philos = (pthread_t **)malloc(sizeof(pthread_t *) * vars->number_of_philo);
	if (philos == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < vars->number_of_philo)
	{
		philos[i] = (pthread_t *)malloc(sizeof(pthread_t));
		if (philos[i] == NULL)
			exit(EXIT_FAILURE);
		i++;
	}
	return (philos);
}
