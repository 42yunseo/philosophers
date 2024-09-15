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
		return (NULL);
	memset(input, -1, sizeof(t_input));
	input->number_of_philo = (int)ft_atol(argv[1]);
	input->die = (int)ft_atol(argv[2]);
	input->eat = (int)ft_atol(argv[3]);
	input->sleep = (int)ft_atol(argv[4]);
	if (argc == 6)
		input->number_of_times_must_eat = (int)ft_atol(argv[5]);
	return (input);
}

t_vars	*vars_init(int argc, char **argv)
{
	t_vars	*vars;

	vars = (t_vars *)malloc(sizeof(t_vars));
	if (vars == NULL)
		return (NULL);
	memset(vars, 0, sizeof(t_vars));
	vars->input = input_init(argc, argv);
	if (vars->input == NULL)
		return (NULL);
	if (pthread_mutex_init(&vars->print_mutex, NULL) != 0)
		return (NULL);
	if (pthread_mutex_init(&vars->eat_num_mutex, NULL) != 0)
		return (NULL);
	if (pthread_mutex_init(&vars->finish_mutex, NULL) != 0)
		return (NULL);
	return (vars);
}

t_philo	*philo_init(t_vars *vars, int id)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	memset(philo, 0, sizeof(t_philo));
	philo->id = id;
	philo->vars = vars;
	philo->l_fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	philo->l_fork = (int *)malloc(sizeof(int));
	philo->eat_cnt_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	philo->last_eat_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	return (philo);
}

t_philo	**philos_init(t_vars *vars)
{
	t_philo	**philo;
	int		i;
	int		size;

	size = vars->input->number_of_philo;
	philo = (t_philo **)malloc(sizeof(t_philo *) * size);
	if (philo == NULL)
		return (NULL);
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
		return (NULL);
	return (thread);
}
