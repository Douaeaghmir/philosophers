#include "philosopher.h"
pthread_mutex_t *t_mutex_alloc(void)
{
    pthread_mutex_t *info;

    info= malloc(sizeof(pthread_mutex_t));
    if(!info)
        return(NULL);
    if(pthread_mutex_init(info, NULL) != 0)
        return(NULL);
    return(info);
}