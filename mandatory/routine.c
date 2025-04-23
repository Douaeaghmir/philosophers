#include "philosopher.h"
void *routine_daily(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    if(philo->id % 2 == 0)
        usleep(1000);
    while(1)
    {
        philo_eat(philo);
        usleep(100);
        philo_think(philo);
        usleep(100);
        philo_sleep(philo);
    }
    return (NULL);
}
void philo_eat(t_philo *philo)
{
    pthread_mutex_lock(philo->r_fork);
    print_status(philo, "has taken a fork");
    pthread_mutex_lock(philo->l_fork);
    print_status(philo, "has taken a fork");
    pthread_mutex_lock(philo->group->meal_lock);
    philo->eating_flag = 1;
    philo->last_meal = time_cal();
    print_status(philo, "is eating");
    pthread_mutex_unlock(philo->group->meal_lock);
    usleep(philo->group->time_to_eat * 1000);
    philo->counter_meal++;
    philo->eating_flag = 0;
    pthread_mutex_unlock(philo->r_fork);
    pthread_mutex_unlock(philo->l_fork);
}


void philo_think(t_philo *philo)
{
    print_status(philo, "is thinking");
}
void philo_sleep(t_philo *philo)
{
    print_status(philo, "is sleep");
    usleep(philo->group->time_to_sleep * 1000);
}