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

void	monitoring(t_vars *vars, t_philo **philos)
{
	while (1)
	{
		if (detect_finish(vars) == FINISH)
			return ;
		detect_starvation(vars, philos);
		if (vars->input->number_of_times_must_eat != -1)
			detect_eat_cnt(vars);
		usleep(1000);
	}
}

void	run(t_vars *vars, t_philo **philos, pthread_t *threads)
{
	int	i;
	int	size;

	i = 0;
	size = vars->input->number_of_philo;
	vars->start_time = getms();
	while (i < size)
	{
		pthread_create(&threads[i], NULL, start_routine, philos[i]);
		i++;
	}
	i = 0;
	monitoring(vars, philos);
	while (i < size)
		pthread_join(threads[i++], NULL);
}

int	check_integer(char *str)
{
	if (str == NULL)
		return (1);
	if (ft_atol(str) <= 0 || ft_atol(str) > __INT_MAX__)
		return (1);
	while (ft_isdigit(*str))
		str++;
	if (*str != '\0')
		return (1);
	return (0);
}

int	check_input(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
	{
		printf("Error : Invalid number of arguments.\n");
		return (1);
	}
	i = 0;
	while (++i < argc)
	{
		if (check_integer(argv[i]))
		{
			printf("Error : Invalid input.\n");
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars		*vars;
	t_philo		**philos;
	pthread_t	*ph_threads;
	int			size;

	if (check_input(argc, argv) != 0)
		return (0);
	vars = vars_init(argc, argv);
	if (vars == NULL)
		return (1);
	size = vars->input->number_of_philo;
	philos = philos_init(vars);
	if (philos == NULL)
		return (1);
	set_philo(philos, size);
	ph_threads = thread_init(size);
	if (ph_threads == NULL)
		return (1);
	run(vars, philos, ph_threads);
	free_all(vars, philos, ph_threads);
	return (0);
}
