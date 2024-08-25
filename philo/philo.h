/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:57:03 by yunseo            #+#    #+#             */
/*   Updated: 2024/08/16 23:23:41 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_vars
{
	int			number_of_philo;
	suseconds_t	die;
	suseconds_t	eat;
	suseconds_t	sleep;
	int			number_of_times_must_eat;
}t_vars;

typedef struct s_philo
{
	int				number;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}t_philo;

// eat -> sleep -> think -> eat -> ...

t_vars	*vars_init(int argc, char **argv);
t_philo	**philo_init(int size);

// utils.c
long	ft_atol(const char *nptr);

#endif
