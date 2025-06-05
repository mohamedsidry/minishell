/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 15:29:39 by msidry            #+#    #+#             */
/*   Updated: 2025/06/05 16:10:45 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"

int ft_atoi(char *nbr);

char *ft_itoa(char *nbr)
{
    int number;
    int tmp;
    int len;
    char *result;

    len = 0;
    number = ft_atoi(nbr);
    if (number == 0)
        return (ft_strdup("0"));
    number++;
    tmp = number;
    while (tmp > 0)
    {
        tmp /= 10;
        len++;
    }
    result = ft_calloc(len + 1, sizeof(char));
    if (!result)
        return (ft_strdup("0"));
    while (number > 0)
    {
        result[--len] = number % 10  + '0';
        number /= 10;
    }
    return (result);
}


int ft_atoi(char *nbr)
{
    int number;
    int sign;

    sign = 1;
    number = 0;
    if (!nbr)
        return (0);
    while (*nbr && (*nbr >= '0' && *nbr <= '9'))
    {
        number = number * 10 + (*nbr - '0');
        nbr++;
    }
    return (number * sign);
}