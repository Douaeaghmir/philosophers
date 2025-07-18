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

