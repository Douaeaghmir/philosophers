#include "philosopher.h"
t_philo init_philo(t_group *info ,pthread_mutex_t *forks)
{
    int i;
    
    i = 0;
    while(i < info->philos[i].num_of_philo)
    {
        info->philos[i].id = i + 1;
        info->philos[i].eating = false;
        info->philos[i].num_time_to_eat = 0;
        info->philos[i].dead = info->philos[i].die_lock;
        info->philos[i].start_meal = cal_time();
        info->philos[i].last_meal = cal_time();
        info->philos[i].end_lock = info->philos[i].lock;
        info->r_lock = &forks[i];
        info->l_lock = &forks[(i + 1) % info->philos[i].num_of_philo];
    }
}