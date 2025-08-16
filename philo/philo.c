/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doaghmir <doaghmir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 00:19:14 by doaghmir          #+#    #+#             */
/*   Updated: 2025/08/11 18:41:31 by doaghmir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	ft_init(int ac, char **av, t_group *philo)
{
	philo->monitor = malloc(sizeof(pthread_t));
	if (!philo->monitor)
		return (1);
	philo->num_of_philo = ft_numbe_of_philo(av[1]);
	philo->time_to_die = ft_time_proc(av[2]);
	philo->time_to_eat = ft_time_proc(av[3]);
	philo->time_to_sleep = ft_time_proc(av[4]);
	if (ft_check_value(philo->num_of_philo, "wrong argument for philos\n")
		|| ft_check_value(philo->time_to_die,
			"wrong argument for time to die\n")
		|| ft_check_value(philo->time_to_eat,
			"wrong argument for time to eat\n")
		|| ft_check_value(philo->time_to_sleep,
			"wrong argument for time to sleep\n"))
		return (1);
	if (ac == 6)
	{
		philo->num_time_to_eat = ft_nbtime_proc(av[5]);
		if (philo->num_time_to_eat < 0)
			return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_group	philo;

	if (ac != 5 && ac != 6)
	{
		write(2, "wrong pass of arguments\n", 24);
		return (-1);
	}
	if (ft_init(ac, av, &philo) || fork_mutex(&philo))
	{
		free(philo.monitor);
		write(2, "failed to create a thread\n", 26);
		return (-1);
	}
	init_philo(&philo);
	ft_thread(&philo);
	pthread_create(philo.monitor, NULL, monitor_death, &philo);
	pthread_join(*philo.monitor, NULL);
	ft_join(&philo);
	ft_destroypiw(&philo);
	free(philo.monitor);
}
