#include "philosopher.h"

int all_philos_full(t_group *group)
{
    int i;
    int full = 0;

    pthread_mutex_lock(&group->meal_lock); 
    i = 0;
    while (i < group->num_of_philo)
    {
        if (group->philos[i].counter_meal >= group->num_time_to_eat)
            full++;
        i++;
    }
    pthread_mutex_unlock(&group->meal_lock);  
    return (full == group->num_of_philo);
}
void ft_usleep(long time, t_philo *arg)
{
    long beginning;

    beginning = time_cal();

    if(beginning < 0)
    return;
    while((time_cal() - beginning) < time && !check_flag(arg))
    usleep(50);
}
int check_flag(t_philo *arg)
{
    pthread_mutex_lock(&arg->group->dead_lock);
    if(arg->group->dead_flag)
    {
        pthread_mutex_unlock(&arg->group->dead_lock);
        return(1);
    }
    pthread_mutex_unlock(&arg->group->dead_lock);
    return(0);
}