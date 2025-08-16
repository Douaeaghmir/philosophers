/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doaghmir <doaghmir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 00:19:10 by doaghmir          #+#    #+#             */
/*   Updated: 2025/08/15 05:21:00 by doaghmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	fork_mutex(t_group *nb)
{
	int	i;

	pthread_mutex_init(&nb->dead_lock, NULL);
	pthread_mutex_init(&nb->meal_lock, NULL);
	pthread_mutex_init(&nb->write_lock, NULL);
	nb->forks = malloc(sizeof(pthread_mutex_t) * nb->num_of_philo);
	if (!nb->forks)
		return (1);
	i = 0;
	while (i < nb->num_of_philo)
	{
		pthread_mutex_init(&nb->forks[i], NULL);
		i++;
	}
	nb->philos = malloc(sizeof(t_philo) * nb->num_of_philo);
	if (!nb->philos)
	{
		free(nb->forks);
		return (1);
	}
	return (0);
}

void	ft_free(pthread_mutex_t *fork, int i)
{
	int	x;

	x = 0;
	while (x < i)
	{
		pthread_mutex_destroy(&fork[x]);
		x++;
	}
	own_free((void **)&fork);
}

void	own_free(void **arg)
{
	if (arg && *arg)
	{
		free(*arg);
		*arg = NULL;
	}
}

void	ft_destroypiw(t_group *info)
{
	pthread_mutex_destroy(&info->write_lock);
	pthread_mutex_destroy(&info->meal_lock);
	pthread_mutex_destroy(&info->dead_lock);
	free(info->forks);
	free(info->philos);
}
