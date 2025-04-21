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
	int				start_time;
	int				last_meal;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
    t_group         *group;
}					t_philo;

typedef struct s_group
{
	int				num_of_philo;
	int				num_time_to_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;			
	int				dead_flag;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_group;
long ft_atoi(char *str, int i);
void ft_error(void);
int *fork_mutex(t_group *nb);
void init_philo(t_group *info );
void ft_destroypiw(t_group *info);
long time_cal(void);
void print_status(t_group *philo, char *msg);
#endif