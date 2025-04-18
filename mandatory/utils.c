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
        ft_error();
    while(str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        if (res > (LLONG_MAX / 10) || (res == (LLONG_MAX / 10) && (str[i] - '0') > LLONG_MAX % 10))
            ft_error();
        i++;
    }
    if(str[i])
    ft_error();
    if((res * sign) < INT_MIN || (res * sign) > INT_MAX)
        ft_error();
    return(int)(sign *res);
}
