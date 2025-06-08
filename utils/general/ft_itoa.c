#include "../../include/header.h"

char *ft_itoa(int n)
{
    char *str;
    int len = 0;
    int temp = n;
    
    if (n == 0)
        return (ft_strdup("0"));
    
    while (temp)
    {
        temp /= 10;
        len++;
    }
    
    str = malloc(len + 1);
    if (!str)
        return (NULL);
    
    str[len] = '\0';
    while (len--)
    {
        str[len] = (n % 10) + '0';
        n /= 10;
    }
    
    return (str);
}