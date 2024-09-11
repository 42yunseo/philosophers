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

void	run(t_vars *vars, t_philo **philos, pthread_t *threads, int size)
{
	int	i;

	i = 0;
	vars->start_time = getms();
	while (i < size)
	{
		pthread_create(&threads[i], NULL, start_routine, philos[i]);
		i++;
	}
	i = 0;
	sleep(10);
	pthread_mutex_lock(&vars->finish_mutex);
	vars->finish = FINISH;
	pthread_mutex_unlock(&vars->finish_mutex);
	while (i < size)
		pthread_join(threads[i++], NULL);
}

void	print_philo(t_philo *philo)
{
	printf("===philo %2d status===\n", philo->id);
	printf("vars address : %p\n", philo->vars);
	printf("L_fork addr : %p\n", philo->l_fork_mutex);
	printf("R_fork addr : %p\n", philo->r_fork_mutex);
	printf("L_fork val : %d\n", *philo->l_fork);
	if (philo->r_fork != NULL)
		printf("R_fork val : %d\n", *philo->r_fork);
	printf("eat_mutex : %p\n", philo->eat_cnt_mutex);
	printf("eat_cnt : %d\n", philo->eat_cnt);
	printf("last_eat mutex : %p\n", philo->last_eat_mutex);
	printf("last_eat : %ld\n", philo->last_eat);
	printf("===philo ends===\n");
}

void	print_vars(t_vars *vars)
{
	printf("=====vars status=====\n");
	printf("address : %p\n", vars);
	printf("input : %p\n", vars->input);
	printf("start_time : %ld\n", vars->start_time);
	printf("print_mutex : %p\n", &vars->print_mutex);
	printf("finish_mutex : %p\n", &vars->finish_mutex);
	printf("eat_num_mutex : %p\n", &vars->eat_num_mutex);
	printf("finish val : %d\n", vars->finish);
	printf("eat_num val : %d\n", vars->eat_num);
	printf("=====vars ends=====\n\n");
}

void	print_status(t_vars *vars, t_philo **philos, int size)
{
	int	i;

	print_vars(vars);
	i = 0;
	while (i < size)
		print_philo(philos[i++]);
}

int	main(int argc, char **argv)
{
	t_vars		*vars;
	t_philo		**philos;
	pthread_t	*ph_threads;
	int			size;

	if (argc != 5 && argc != 6)
		return (0);
	vars = vars_init(argc, argv);
	size = vars->input->number_of_philo;
	philos = philos_init(vars, size);
	set_philo(philos, size);
	ph_threads = thread_init(size);
	run(vars, philos, ph_threads, size);
	return (0);
}
