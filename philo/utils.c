/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunseo <yunseo@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:47:11 by yunseo            #+#    #+#             */
/*   Updated: 2024/08/18 17:47:11 by yunseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	ft_atol(const char *nptr)
{
	long	value;
	int		negative;

	value = 0;
	negative = 0;
	if (*nptr == '-')
	{
		negative = 1;
		nptr++;
	}
	while (*nptr && ft_isdigit(*nptr))
		value = value * 10 + *nptr++ - '0';
	if (negative == 1)
		value = -value;
	return (value);
}

suseconds_t	getms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
