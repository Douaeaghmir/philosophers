#include "philosopher.h"
void *routine_daily(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    philo->last_meal = time_cal();

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




void philo_eat(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(philo->l_fork);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(philo->r_fork);
        print_status(philo, "has taken a fork");
    }
    else
    {
        pthread_mutex_lock(philo->r_fork);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(philo->l_fork);
        print_status(philo, "has taken a fork");
    }

    pthread_mutex_lock(&philo->group->meal_lock);
    print_status(philo, "is eating");
    philo->last_meal = time_cal();
    philo->counter_meal++;
    pthread_mutex_unlock(&philo->group->meal_lock);

    ft_usleep(philo->group->time_to_eat, philo);
    pthread_mutex_unlock(philo->l_fork);
    pthread_mutex_unlock(philo->r_fork);
}




void philo_think(t_philo *philo)
{
    print_status(philo, "is thinking");
}
void philo_sleep(t_philo *philo)
{
    print_status(philo, "is sleeping");
    ft_usleep(philo->group->time_to_sleep, philo);
}