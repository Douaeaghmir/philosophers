#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <unistd.h>
#include <pthread.h>
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef struct s_philo
{
    pthread_t       thread;
    int             time_to_eat;
    int             time_to_sleep;
    int             time_to_die;
    int             num_time_to_eat;
	int             num_of_philo;
    int             id;
    bool            eating;
    int             start_meal;
    int             last_meal;
	int             *dead;
    pthread_mutex_t *die_lock;
	pthread_mutex_t *msg_lock;
    pthread_mutex_t *lock;
    pthread_mutex_t *end_lock;
	pthread_mutex_t	*meal_lock;
    t_group *group;

}               t_philo;
typedef struct s_group
{
    int             dead_flag;
    pthread_mutex_t *l_lock;
    pthread_mutex_t *r_lock;
    pthread_mutex_t *meal_lock;
    pthread_mutex_t *end_lock;
    pthread_mutex_t *write_lock;
    pthread_mutex_t *die_lock;
    t_philo         *philos;
}               t_group;
long ft_atoi(char *str, int i);
void ft_error(void);
#endif