#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <unistd.h>
#include <pthread.h>
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/time.h>
typedef struct s_group t_group;
typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating_flag;
	int				counter_meal;
	long				start_time;
	long				last_meal;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
    t_group         *group;
}					t_philo;

typedef struct s_group
{
	int				num_of_philo;
	int				num_time_to_eat;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;			
	int				dead_flag;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*forks;
	t_philo			*philos;
	pthread_t	 *monitor;
}					t_group;
long ft_atoi(char *str, int i);
void ft_error(void);
int fork_mutex(t_group *nb);
void init_philo(t_group *info );
void ft_destroypiw(t_group *info);
long time_cal(void);
void own_free(void **arg);
void ft_free(pthread_mutex_t *fork, int i);
void *routine_daily(void *arg);
void philo_eat(t_philo *philo);
void philo_think(t_philo *philo);
void philo_sleep(t_philo *philo);
int ft_numbe_of_philo(void *arg);
int ft_nbtime_proc(void *arg);
int ft_time_proc(void *arg);
int ft_init(int ac, char **av, t_group *philo);
void ft_thread(t_group *arg);
void print_status(t_philo *philo, char *msg);
pthread_mutex_t *t_mutex_alloc(void);
void ft_join(t_group *arg);
void *monitor_death(void *arg);
int all_philos_full(t_group *group);
#endif