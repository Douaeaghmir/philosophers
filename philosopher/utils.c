/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doaghmir <doaghmir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 00:19:22 by doaghmir          #+#    #+#             */
/*   Updated: 2025/07/27 02:02:17 by doaghmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	ft_atoi(char *str, int i, long res)
{
	int	sign;

	res = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i] || (str[i] < '0' || str[i] > '9'))
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if (res > (LLONG_MAX / 10) || (res == (LLONG_MAX / 10) && (str[i]
					- '0') > LLONG_MAX % 10))
			return (-1);
		i++;
	}
	if (str[i])
		return (-1);
	if ((res * sign) < INT_MIN || (res * sign) > INT_MAX)
		return (-1);
	return ((int)(sign * res));
}

void	ft_thread(t_group *arg)
{
	int	i;

	i = 0;
	while (i < arg->num_of_philo)
	{
		if (pthread_create(&arg->philos[i].thread, NULL, routine_daily,
				&arg->philos[i]) != 0)
			write(2, "failed to create the thread", 27);
		i++;
	}
}

void	ft_join(t_group *arg)
{
	int	i;

	i = 0;
	while (i < arg->num_of_philo)
	{
		pthread_join(arg->philos[i].thread, NULL);
		i++;
	}
}

int	check_philo_died(t_group *info, int i)
{
	if ((time_cal() - info->philos[i].last_meal) > info->time_to_die)
	{
		pthread_mutex_lock(&info->dead_lock);
		info->dead_flag = 1;
		printf("%ld %d died\n", time_cal() - info->philos[i].start_time,
			info->philos[i].id);
		pthread_mutex_unlock(&info->dead_lock);
		return (1);
	}
	return (0);
}

void	*monitor_death(void *arg)
{
	t_group	*info;

	info = (t_group *)arg;
	while (!info->dead_flag)
	{
		if (check_all_philos(info))
			return (NULL);
		if (info->num_time_to_eat > 0 && all_philos_full(info))
		{
			pthread_mutex_lock(&info->dead_lock);
			info->dead_flag = 1;
			pthread_mutex_unlock(&info->dead_lock);
			return (NULL);
		}
		usleep(500);
	}
	return (NULL);
}
