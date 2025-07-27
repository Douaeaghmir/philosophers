/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doaghmir <doaghmir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 00:19:20 by doaghmir          #+#    #+#             */
/*   Updated: 2025/07/27 02:37:53 by doaghmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*routine_daily(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->group->meal_lock);
	philo->last_meal = time_cal();
	pthread_mutex_unlock(&philo->group->meal_lock);
	if (philo->id % 2 == 0)
		ft_usleep(1, philo);
	while (!check_flag(philo))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}

void	philo_eat(t_philo *philo)
{
	if (philo->group->num_of_philo == 1)
	{
		philo_one_fork(philo);
		return ;
	}
	lock_forks(philo);
	pthread_mutex_lock(&philo->group->meal_lock);
	print_status(philo, "is eating");
	philo->last_meal = time_cal();
	philo->counter_meal++;
	pthread_mutex_unlock(&philo->group->meal_lock);
	ft_usleep(philo->group->time_to_eat, philo);
	unlock_forks(philo);
}

void	philo_think(t_philo *philo)
{
	print_status(philo, "is thinking");
}

void	philo_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping");
	ft_usleep(philo->group->time_to_sleep, philo);
}
