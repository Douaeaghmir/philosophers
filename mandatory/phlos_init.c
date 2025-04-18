#include "philosopher.h"
pthread_mutex_t *mutex_end(void)
{
    pthread_mutex_t *end;

    end = malloc(sizeof(pthread_mutex_t));
    if(!end)
        return(NULL);
    if(pthread_mutex_init(end, NULL) != 0)
        return(NULL);
    return(end);
}
pthread_mutex_t *mutex_message(void)
{
    pthread_mutex_t *message;

    message = malloc(sizeof(pthread_mutex_t));
    if(!message)
        return(NULL);
    if(pthread_mutex_init(message, NULL) != 0)
        return(NULL);
    return(message);
}
pthread_mutex_t *mutex_meal(void)
{
    pthread_mutex_t *meal;

    meal = malloc(sizeof(pthread_mutex_t) != 0);
    if(!meal)
        return(NULL);
    if(pthread_mutex_init(meal, NULL) != 0)
        return(NULL);
    return(meal);
}
pthread_mutex_t *fork_mutex(t_philo *nb)
{
    pthread_mutex_t *fork;
    int i;
    fork = malloc(sizeof(pthread_mutex_t) * nb->num_of_philo);
    if(!fork)
        return(NULL);
    i = 0;
    while(i < nb->num_of_philo)
    {
        if(pthread_mutex_init(&fork[i], NULL) != 0)
            return(ft_free(&fork[i], i), NULL);
        i++;
    }
    return(fork);
}
void ft_free(pthread_mutex_t *fork, int i)
{
    int x;
     while (x < i)
    {
        if(pthread_mutex_destroy(&fork[i]) != 0)
            return;
            i++;
    }
    own_free((void **)&fork);
}
void own_free(void **arg)
{
    if(!arg && *arg)
    {
        free(*arg);
        *arg = NULL;
    }
}