/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doaghmir <doaghmir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 01:44:21 by doaghmir          #+#    #+#             */
/*   Updated: 2025/07/27 02:29:25 by doaghmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_numbe_of_philo(void *arg)
{
	int	n;

	if (!arg)
		return (-1);
	n = ft_atoi(arg, 0, 0);
	if (n <= 0)
		return (-1);
	return (n);
}

int	ft_nbtime_proc(char *arg)
{
	int	nb;

	if (!arg)
		return (-1);
	nb = ft_atoi(arg, 0, 0);
	if (nb <= 0)
	{
		write(2, "philo is starving\n", 18);
		return (-1);
	}
	return (nb);
}

int	ft_time_proc(void *arg)
{
	int	tm;

	if (!arg)
		return (-1);
	tm = ft_atoi(arg, 0, 0);
	if (tm < 0)
		return (-1);
	return (tm);
}

int	ft_check_value(int value, char *msg)
{
	if (value < 0)
	{
		write(2, msg, ft_strlen(msg));
		return (1);
	}
	return (0);
}

int	check_all_philos(t_group *info)
{
	int	i;

	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_mutex_lock(&info->meal_lock);
		if (check_philo_died(info, i))
		{
			pthread_mutex_unlock(&info->meal_lock);
			return (1);
		}
		pthread_mutex_unlock(&info->meal_lock);
		i++;
	}
	return (0);
}
