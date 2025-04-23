#include "philosopher.h"
int fork_mutex(t_group *nb)
{
    nb->dead_lock = t_mutex_alloc();
    nb->meal_lock = t_mutex_alloc();
    nb->write_lock = t_mutex_alloc();
    int i;
    nb->forks = malloc(sizeof(pthread_mutex_t) * nb->num_of_philo);
    if(!nb->forks)
        return(1);
    i = 0;
    while(i < nb->num_of_philo)
    {
        pthread_mutex_init(&nb->forks[i], NULL);
        i++;
    }
    nb->philos = malloc(sizeof(t_philo) * nb->num_of_philo);
        if(!nb->philos)
            return(1);
        return(0);
}

void ft_free(pthread_mutex_t *fork, int i)
{
    int x;

    x = 0;
     while (x < i)
    {
        pthread_mutex_destroy(&fork[x]);
        x++;
    }
    own_free((void **)&fork);
}
void own_free(void **arg)
{
    if(arg && *arg)
    {
        free(*arg);
        *arg = NULL;
    }
}

void ft_destroypiw(t_group *info)
{
    int i;

    i = 0;
    while(i < info->num_of_philo)
    {
        pthread_mutex_destroy(&info->forks[i]);
        i++;
    }
    pthread_mutex_destroy(info->write_lock);
    pthread_mutex_destroy(info->meal_lock);
    pthread_mutex_destroy(info->dead_lock);
    free(info->forks);
    free(info->philos);
    free(info->write_lock);
    free(info->dead_lock);
    free(info->meal_lock);
}
