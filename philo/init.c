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

t_input	*input_init(int argc, char **argv)
{
	t_input	*input;

	input = (t_input *)malloc(sizeof(t_input));
	if (input == NULL)
		exit(EXIT_FAILURE);
	memset(input, -1, sizeof(t_input));
	input->number_of_philo = atoi(argv[1]);
	input->die = ft_atol(argv[2]);
	input->eat = ft_atol(argv[3]);
	input->sleep = ft_atol(argv[4]);
	if (argc == 6)
		input->number_of_times_must_eat = atoi(argv[5]);
	return (input);
}

t_vars	*vars_init(int argc, char **argv)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (vars == NULL)
		exit(EXIT_FAILURE);
	memset(vars, 0, sizeof(t_vars));
	vars->input = input_init(argc, argv);
	if (pthread_mutex_init(&vars->print_mutex, NULL) != 0)
		exit(EXIT_FAILURE);
	if (pthread_mutex_init(&vars->eat_num_mutex, NULL) != 0)
		exit(EXIT_FAILURE);
	if (pthread_mutex_init(&vars->finish_mutex, NULL) != 0)
		exit(EXIT_FAILURE);
	return (vars);
}

t_philo	*philo_init(t_vars *vars, int id)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (philo == NULL)
		exit(EXIT_FAILURE);
	memset(philo, 0, sizeof(t_philo));
	philo->id = id;
	philo->vars = vars;
	philo->l_fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	philo->l_fork = (int *)malloc(sizeof(int));
	philo->eat_cnt_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	philo->last_eat_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	return (philo);
}

t_philo	**philos_init(t_vars *vars, int size)
{
	t_philo	**philo;
	int		i;

	philo = (t_philo **)malloc(sizeof(t_philo *) * size);
	if (philo == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < size)
	{
		philo[i] = philo_init(vars, i + 1);
		i++;
	}
	return (philo);
}

pthread_t	*thread_init(int size)
{
	pthread_t	*thread;

	thread = (pthread_t *)malloc(sizeof(pthread_t) * size);
	if (thread == NULL)
		exit(EXIT_FAILURE);
	return (thread);
}
