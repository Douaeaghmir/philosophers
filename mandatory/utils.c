#include "philosopher.h"
long ft_atoi(char *str, int i)
{
    int sign;
    long res;

    res = 0;
    sign = 1;
    while(str[i] == ' ')
    i++;
    if(str[i] == '-')
        sign = -1;
    if(str[i] == '+' || str[i] == '-')
    i++;
    if(!str[i] || (str[i] < '0' && str[i] > '9'))
        return(-1);
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        if (res > (LLONG_MAX / 10) || (res == (LLONG_MAX / 10) && (str[i] - '0') > LLONG_MAX % 10))
            return(-1);
        i++;
    }
    if(str[i])
    return(-1);
    if((res * sign) < INT_MIN || (res * sign) > INT_MAX)
        return(-1);
    return(int)(sign *res);
}
