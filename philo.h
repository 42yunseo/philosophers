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
	pthread_mutex_t	fork;
}t_philo;

typedef struct s_list
{
	t_philo			*philo;
	struct s_list	*next;
}t_list;

typedef struct s_table
{
	t_list	*front;
	t_list	*rear;
}t_table;

t_vars	*vars_init(int argc, char **argv);

#endif
