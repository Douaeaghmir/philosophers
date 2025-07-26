#include "philosopher.h"
int ft_numbe_of_philo(void *arg)
{
    int n;

    if(!arg)
        return(-1);
    n = ft_atoi(arg,0);
    if(n <= 0) 
        return(-1);
    return(n);
}
int ft_nbtime_proc(char *arg)
{
    int nb;

    if(!arg)
        return(-1);
    nb = ft_atoi(arg, 0);

    if( nb < 0)
    {
        write(2, "philo is starving\n", 18);
        return(-1);
    }
    return(nb);
}
int ft_time_proc(void *arg)
{
    int tm;

    if(!arg)
        return(-1);
    tm = ft_atoi(arg, 0);
    if(tm < 0)
        return(-1);
    return(tm);
}
int ft_init(int ac, char **av, t_group *philo)
{
    philo->monitor = malloc(sizeof(pthread_t));
    philo->num_of_philo = ft_numbe_of_philo(av[1]);
    philo->time_to_die = ft_time_proc(av[2]);
    philo->time_to_eat = ft_time_proc(av[3]);
    philo->time_to_sleep = ft_time_proc(av[4]);
    if(philo->num_of_philo < 0)
    {
        write(2, "wrong argument for philos\n", 26);
        return(1);
    }
    if(philo->time_to_die < 0)
    {
        write(2, "wrong argument for time to die\n", 31);
        return(1);
    }
    if(philo->time_to_eat < 0)
    {
        write(2, "wrong argument for time to eat\n", 31);
        return(1);
    }
    if(philo->time_to_sleep < 0)
    {
        write(2, "wrong argument for time to sleep\n", 33);
        return(1);
    }
    if(ac == 6)
        philo->num_time_to_eat = ft_nbtime_proc(av[5]);
    if(philo->num_time_to_eat < 0)
        return 1;
    return(0);
}
void f()
{
    system("leaks philo");
}
int main(int ac, char **av)
{
    t_group philo;
    atexit(f);
    if(ac != 5 && ac != 6)
    {
        write(2, "wrong pass of arguments\n", 24);
        return (-1);
    }
    if(ft_init(ac, av, &philo) || fork_mutex(&philo))
    {
        free(philo.monitor);
        write(2, "failed to create a thread\n", 26);
        return(-1);
    }
    init_philo(&philo);
    ft_thread(&philo);
    pthread_create(philo.monitor, NULL, monitor_death, &philo);
    pthread_join(*philo.monitor, NULL);
    ft_join(&philo);
    ft_destroypiw(&philo);
    free(philo.monitor);
}
