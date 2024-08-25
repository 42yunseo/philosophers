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

t_philo	**philos_init(int size)
{
	t_philo	**philo;
	int		i;

	philo = (t_philo **)malloc(sizeof(t_philo *) * size);
	if (philo == NULL)
		exit(EXIT_FAILURE);
	memset(philo, 0, sizeof(t_philo *));
	i = 0;
	while (i < size)
	{
		philo[i] = (t_philo *)malloc(sizeof(t_philo));
		if (philo[i] == NULL)
			exit(EXIT_FAILURE);
		memset(philo[i], 0, sizeof(t_philo));
		i++;
	}
	return (philo);
}

pthread_mutex_t	**fork_init(int size)
{
	pthread_mutex_t	**fork;
	int				i;

	fork = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *) * size);
	if (fork == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < size)
		if (pthread_mutex_init(fork[i++], NULL) != 0)
			exit(EXIT_FAILURE);
	return (fork);
}