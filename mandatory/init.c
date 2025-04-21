#include "philosopher.h"
void init_philo(t_group *info )
{
    int i;
    
    i = 0;
    while(i < info->num_of_philo)
    {
        info->philos[i].id = i + 1;
        info->philos[i].eating_flag = 0;
        info->philos[i].counter_meal = 0;
        info->philos[i].last_meal = time_cal();
        info->philos[i].start_time = time_cal();
        info->dead_flag = 0;
        info->philos[i].group = info;
        info->philos[i].l_fork = &info->forks[i];
        info->philos[i].r_fork = &info->forks[(i + 1) % info->num_of_philo];
    }
}
long time_cal(void)
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return((time.tv_sec / 1000LL) + (time.tv_usec / 1000));
}
void print_status(t_group *philo, char *msg)
{
    pthread_mutex_lock(philo->write_lock);
    if(!philo->dead_lock)
    printf("%d %d %s\n", time_cal - philo->philos->start_time, philo->philos->id, msg);
    pthread_mutex_unlock(philo->write_lock);
}