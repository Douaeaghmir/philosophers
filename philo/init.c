/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doaghmir <doaghmir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 00:19:07 by doaghmir          #+#    #+#             */
/*   Updated: 2025/07/27 00:19:08 by doaghmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	init_philo(t_group *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philo)
	{
		info->philos[i].id = i + 1;
		info->philos[i].eating_flag = 0;
		info->philos[i].counter_meal = 0;
		info->philos[i].last_meal = time_cal();
		info->philos[i].start_time = time_cal();
		info->philos[i].group = info;
		info->philos[i].l_fork = &info->forks[i];
		info->philos[i].r_fork = &info->forks[(i + 1) % info->num_of_philo];
		i++;
	}
	info->dead_flag = 0;
}

long	time_cal(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000LL) + (time.tv_usec / 1000));
}

void	print_status(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->group->dead_lock);
	if (!philo->group->dead_flag)
	{
		pthread_mutex_lock(&philo->group->write_lock);
		printf("%ld %d %s\n", time_cal() - philo->start_time, philo->id, msg);
		pthread_mutex_unlock(&philo->group->write_lock);
	}
	pthread_mutex_unlock(&philo->group->dead_lock);
}
