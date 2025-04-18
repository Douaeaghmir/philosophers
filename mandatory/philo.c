#include "philosopher.h"
int routine();
int ft_numbe_of_philo(void *arg)
{
    int n;

    n = ft_atoi(arg,0);
    if(!arg)
        return(-1);
    if(n <= 0) 
        return(-1);
    return(n);
}
int ft_nbtime_proc(void *arg)
{
    int nb;

    nb = ft_atoi(arg, 0);
    if(!arg)
        return(-1);
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

    tm = ft_atoi(arg, 0);
    if(!arg)
        return(-1);
    if(tm < 0)
        return(-1);
    return(tm);
}
void ft_init(int ac, char **av, t_philo *philo)
{
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
        write(2, "wrong argument for time to die\n", 21);
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
}
void ft_error(void)
{
    write(2, "error\n", 6);
}
int main(int ac, char **av)
{
    t_philo philo;
    if( ac != 5 && ac != 6)
    write(2, "wrong pass of arguments\n", 24);
    return (-1);
    ft_init(ac, av, &philo);
}