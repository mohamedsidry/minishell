/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:33:45 by msidry            #+#    #+#             */
/*   Updated: 2025/05/15 14:40:00 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/header.h"


size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t count;
    size_t len;

    count = 0;
    len = ft_strlen(src);
    if (!dst || !src)
        return (len);
    if (count < size)
    {
        while (*src && count < size - 1)
        {
            *dst = *src;
            dst++;
            src++;
            count++;
        }
        *dst = '\0';
    }
    return (len);
}
